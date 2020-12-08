
#include "ScaleFactors.h"


void RemoveDuplicatesAndSort(std::vector<float> &v)
{
    std::unordered_set<float> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());
    std::sort(v.begin(),v.end());
}


LeptonScaleFactor::LeptonScaleFactor(std::string const& leptonsfpath){
  ifstream file("src/scalefactors/LeptonSF.csv");
  string line = "";
  int counter = 0;
  vector<vector<float> > ptmin, ptmax, etamin, etamax, SF, SFerr;
  vector<float> ptmin_, ptmax_, etamin_, etamax_, SF_, SFerr_;
  vector<string> histname;
  string histname_ = "hSF";
  while(getline(file,line)){
    //std::cout << line << endl;
    if(char(line[0])==char('P')) {
      if(counter>0){
        ptmin.push_back(ptmin_);
        ptmax.push_back(ptmax_);
        etamin.push_back(etamin_);
        etamax.push_back(etamax_);
        SF.push_back(SF_);
        SFerr.push_back(SFerr_);
        histname.push_back(histname_);
        //cout << histname_ << endl;
      }
      ptmin_.clear(); ptmax_.clear(); etamin_.clear(); etamax_.clear(), SF_.clear(), SFerr_.clear();
      histname_ = "hSF";
      ++counter;
      continue;
    }//skip first line
    string _tagger, _theperiod, _theWP, temp;
    //int _theyear;
    int _pdgid,_ptmin,_ptmax;
    float _etamin,_etamax,_cent,_err;
    std::string::iterator end_pos;
    stringstream ss(line);
    getline(ss,temp,',');
    _pdgid = stoi(temp);
    //cout << _pdgid << " histname_ " << histname_ << " " << (histname_.find("_ele") == string::npos) << endl;
    if(abs(_pdgid)==11 && (histname_.find("_ele") == string::npos)) histname_ += "_ele";
    if(abs(_pdgid)==13 && (histname_.find("_muo") == string::npos)) histname_ += "_muo";
    getline(ss,temp,',');
    _theWP = temp;
    end_pos = std::remove(_theWP.begin(), _theWP.end(), ' ');
    _theWP.erase(end_pos, _theWP.end());
    if(histname_.find(_theWP) == string::npos) histname_ += ("_"+_theWP);
    getline(ss,temp,',');
    //_theyear = stoi(temp);
    if(histname_.find(temp) == string::npos) histname_ += ("_"+temp);
    getline(ss,temp,',');
    _theperiod = temp;
    end_pos = std::remove(_theperiod.begin(), _theperiod.end(), ' ');
    _theperiod.erase(end_pos, _theperiod.end());
    if(_theperiod!="X" && histname_.find(_theperiod) == string::npos) histname_ += ("_"+_theperiod);
    getline(ss,temp,',');
    _ptmin = stoi(temp);
    getline(ss,temp,',');
    _ptmax = stoi(temp); 
    getline(ss,temp,',');
    _etamin = stof(temp);
    getline(ss,temp,',');
    _etamax = stof(temp);
    getline(ss,temp,',');
    _cent = stof(temp);
    getline(ss,temp,',');
    _err = stof(temp);
    //cout << _ptmin << " " << _ptmax << " " << _etamin << " " << _etamax << " " << _cent << " " << _err << endl;
    //now push these into appropriately split vectors
    ptmin_.push_back(_ptmin);
    ptmax_.push_back(_ptmax);
    etamin_.push_back(_etamin);
    etamax_.push_back(_etamax);
    SF_.push_back(_cent);
    SFerr_.push_back(_err);
  }
  //last iteration
  ptmin.push_back(ptmin_);
  ptmax.push_back(ptmax_);
  etamin.push_back(etamin_);
  etamax.push_back(etamax_);
  SF.push_back(SF_);
  SFerr.push_back(SFerr_);
  histname.push_back(histname_);
  for(unsigned int i = 0; i<histname.size(); ++i){
    //std::cout << histname[i] << "   " << __LINE__ << std::endl;
    vector<float> ptvec = ptmin[i];    ptvec.push_back( ptmax[i][ ptmax[i].size()-1]);
    vector<float> etavec = etamin[i]; etavec.push_back(etamax[i][etamax[i].size()-1]);
    //for(unsigned int i = 0; i<ptvec.size(); ++i) cout << ptvec[i] << " "; cout << endl;
    //for(unsigned int i = 0; i<etavec.size(); ++i) cout << etavec[i] << " "; cout << endl;
    RemoveDuplicatesAndSort(ptvec);
    RemoveDuplicatesAndSort(etavec);        
    const int nbinspt  =  ptvec.size();
    const int nbinseta = etavec.size();
    double binspt[nbinspt], binseta[nbinseta];
    std::copy(ptvec.begin(),ptvec.end(),binspt);
    std::copy(etavec.begin(),etavec.end(),binseta);
    //for(unsigned int i = 0; i<ptvec.size(); ++i) cout << ptvec[i] << " "; cout << endl;
    //for(unsigned int i = 0; i<etavec.size(); ++i) cout << etavec[i] << " "; cout << endl;
    hSFlep[histname[i] ] = new TH2F(histname[i].c_str(), histname[i].c_str(), nbinspt-1, binspt, nbinseta-1, binseta);
    for(unsigned int j = 0; j<SF[i].size(); ++j){
      int b = hSFlep[histname[i] ]->FindBin(ptmin[i][j]+0.001,etamin[i][j]+0.001);
      hSFlep[histname[i] ]->SetBinContent(b,SF[i][j]);
      hSFlep[histname[i] ]->SetBinError(  b,SFerr[i][j]);
    }
  }
}

      
LeptonScaleFactor::~LeptonScaleFactor(){
  //need to fix this: Segmentation fault (core dumped)
  //for(map<string,TH2F*>::iterator h=hSFlep.begin(); h!=hSFlep.end();++h){
  //  h->second->Delete();
  //}
}
float LeptonScaleFactor::leptonSF(bool isdata, int year, int pdgid, float eta, float pt, int run, int variation){


  if(isdata) return 1.;
  string period = "";
  if(abs(pdgid)==13&&year==2016){
    if(run<=278808) period = "_BCDEF";
    else            period = "_GH";
  }
  float myeta = eta;
  if(abs(pdgid)==13&&year!=2016) myeta = abs(myeta);
  string histname = "hSF";
  if(abs(pdgid)==11) histname += "_ele_MVA90";
  else if(abs(pdgid)==13) histname += "_muo_mediumID";
  histname += ("_" + std::to_string(year) + period);
  //std::cout << histname << "   " << __LINE__ << std::endl;
  float SF(1.), SFerr(0.);
  int bin = hSFlep[histname]->FindBin(std::min(hSFlep[histname]->GetXaxis()->GetBinLowEdge(hSFlep[histname]->GetNbinsX()+1)-0.001,std::max(hSFlep[histname]->GetXaxis()->GetBinLowEdge(1),double(pt))),std::min(hSFlep[histname]->GetYaxis()->GetBinLowEdge(hSFlep[histname]->GetNbinsY()+1)-0.001,std::max(hSFlep[histname]->GetYaxis()->GetBinLowEdge(1),double(myeta))));
  SF = hSFlep[histname]->GetBinContent(bin);
  SFerr = hSFlep[histname]->GetBinContent(bin);
  if(abs(pdgid)==11){
    if (variation ==  0){
      return SF;
    }
    if (variation ==  1){
      return SF+SFerr;
    }
    if (variation == -1){
      return SF-SFerr;
    }
  }
  float SF2(1.), SF2err(0.);
  string histname2 = histname;
  size_t index = histname2.find(string("mediumID"), index);
  histname2.replace(index, string("mediumID").length(), string("looseIso"));
  bin = hSFlep[histname2]->FindBin(std::min(hSFlep[histname2]->GetXaxis()->GetBinLowEdge(hSFlep[histname2]->GetNbinsX()+1)-0.001,std::max(hSFlep[histname2]->GetXaxis()->GetBinLowEdge(1),double(pt))),std::min(hSFlep[histname2]->GetYaxis()->GetBinLowEdge(hSFlep[histname2]->GetNbinsY()+1)-0.001,std::max(hSFlep[histname2]->GetYaxis()->GetBinLowEdge(1),double(myeta))));
  SF2 = hSFlep[histname2]->GetBinContent(bin);
  SF2err = hSFlep[histname2]->GetBinContent(bin);
    if (variation ==  0){
      return SF*SF2;
    }
    if (variation ==  1){
      return SF*SF2+sqrt(pow(SF*SF2err,2)+pow(SF2*SFerr,2));
    }
    if (variation == -1){
      return SF*SF2-sqrt(pow(SF*SF2err,2)+pow(SF2*SFerr,2));
    }
    return SF;

}

//LeptonScaleFactor leptonscalefactors = LeptonScaleFactor();


namespace sf {
  float LeptonSF(int id, int WP, bool iso, int year, string period, bool isdata, int updown, float pt, float nonabseta){
    //PDGid,WP,year,period,ptmin,ptmax,etamin,etamax,SF,SFerr
    if(isdata)
      return 1.;
    float eta = nonabseta;
    if(id==13 && year > 2016) eta = abs(eta);
    float ptminCut = 10.;
    if(id==13) ptminCut = 20;
    float ptmaxCut = 500.;
    if(id==13) ptmaxCut = 120;
    float etaminCut = -2.5;
    if(id==13 && year == 2016) etaminCut = -2.4;
    else if(id==13) etaminCut = 0;
    float etamaxCut = 2.5;
    if(id==13) etamaxCut = 2.4;
    ifstream file("src/scalefactors/LeptonSF.csv");
    string line = "";
    float SF = 1;
    while(getline(file,line)){
      //std::cout << line << endl;
      if(char(line[0])==char('P')) continue;//skip first line
      string tagger, theperiod, theWP, temp;
      int theyear;
      int pdgid,ptmin,ptmax;
      float etamin,etamax,cent,dn,up;
      std::string::iterator end_pos;
      stringstream ss(line);
      getline(ss,temp,',');
      pdgid = stoi(temp);
      if(abs(pdgid)!=abs(id)) continue;
      getline(ss,temp,',');
      theWP = temp;
      end_pos = std::remove(theWP.begin(), theWP.end(), ' ');
      theWP.erase(end_pos, theWP.end());
      //if(id==11 && theWP=="MVA90" && WP!=0) continue;//only one WP implemented right now
      if(id==13 && theWP=="mediumID" &&  iso) continue;//do ID,  not Iso
      if(id==13 && theWP=="looseIso" && !iso) continue;//do Iso, not ID
      getline(ss,temp,',');
      theyear = stoi(temp);
      if(theyear!=year) continue;
      getline(ss,temp,',');
      theperiod = temp;
      end_pos = std::remove(theperiod.begin(), theperiod.end(), ' ');
      theperiod.erase(end_pos, theperiod.end());
      if(theperiod=="BCDEF" && char(period[0])!=char('B')) continue;//not sure this is the way I want to handle things
      if(theperiod=="GH"    && char(period[0])!=char('G')) continue;//not sure this is the way I want to handle things
      getline(ss,temp,',');
      ptmin = stoi(temp);
      if(pt<=ptminCut && ptmin!=ptminCut) continue;
      else if(pt>=ptminCut && pt<ptmin)   continue;
      getline(ss,temp,',');
      ptmax = stoi(temp);
      if(pt>=ptmaxCut && ptmax!=ptmaxCut) continue;
      else if(pt<=ptmaxCut && pt>ptmax)   continue; 
      getline(ss,temp,',');
      etamin = stof(temp);
      if(eta<=etaminCut && etamin!=etaminCut) continue;
      else if(eta>=etaminCut && eta<etamin)   continue;
      getline(ss,temp,',');
      etamax = stof(temp);
      if(eta>=etamaxCut && etamax!=etamaxCut) continue;
      else if(eta<=etamaxCut && eta>etamax)   continue; 
      getline(ss,temp,',');
      cent = stof(temp);
      getline(ss,temp,',');
      dn = stof(temp);
      getline(ss,temp,',');
      up = stof(temp);
      //std::cout << cent << " " << up << " " << dn << std::endl;
      if(updown==0) SF = cent;
      if(updown >0) SF = cent+up;
      if(updown <0) SF = cent-dn;
      break;
    }
    return SF;
  }
  float LeptonSFtot(int id, int WP, int year, string period,  bool isdata, int updown, float pt, float nonabseta){
    if(isdata)
      return 1.;
    if(id==11) return LeptonSF(id, WP, true, year, period, isdata, updown, pt, nonabseta);
    if(id==13){
      float centid  = LeptonSF(id, WP, false, year, period, isdata, 0, pt, nonabseta);
      float centiso = LeptonSF(id, WP, true,  year, period, isdata, 0, pt, nonabseta);
      if(updown==0) return centid * centiso;
      else{
        float updnid  = LeptonSF(id, WP, false, year, period, isdata, updown, pt, nonabseta);
        float updniso = LeptonSF(id, WP, true,  year, period, isdata, updown, pt, nonabseta);
        float diff1 = (centid -updnid )*centiso;
        float diff2 = (centiso-updniso)*centid;
        if(updown>0) return centid*centiso + sqrt(diff1*diff1+diff2*diff2);
        if(updown<0) return centid*centiso - sqrt(diff1*diff1+diff2*diff2);
      }
    }
    return 1.;
  }

  
  float BtagSF(  int WP, int year,  bool isdata, int updown, float pt, float eta){
    //does the nanoAOD weight have only central value or all // don't implement for now
    return 1.;
  }
  float FatjetWSF(int WP, int year,  bool isdata, int updown, float pt){//semi hard-coded
    if(isdata)
      return 1.;
    ifstream file("src/scalefactors/DeepAK8V2_Top_W_SFs.csv");
    string line = "";
    float SF = 1;
    while(getline(file,line)){
      //cout << line << endl;
      if(char(line[0])==char('D')) continue;//skip first line
      string tagger, taggertype, theWP, temp;
      int theyear;
      int ptmin,ptmax;
      float cent,dn,up;
      std::string::iterator end_pos;
      stringstream ss(line);
      getline(ss,temp,',');
      tagger = temp;
      end_pos = std::remove(tagger.begin(), tagger.end(), ' ');
      tagger.erase(end_pos, tagger.end());
      if(tagger!="W") continue;
      getline(ss,temp,',');
      theyear = stoi(temp);
      if(theyear!=year) continue;
      getline(ss,temp,',');
      taggertype = temp;
      end_pos = std::remove(taggertype.begin(), taggertype.end(), ' ');
      taggertype.erase(end_pos, taggertype.end());
      if(taggertype!="MassDecorr") continue;
      getline(ss,temp,',');
      theWP = temp;
      end_pos = std::remove(theWP.begin(), theWP.end(), ' ');
      theWP.erase(end_pos, theWP.end());
      if(theWP=="5p0" && WP!=0) continue;
      if(theWP=="2p5" && WP!=1) continue;
      if(theWP=="1p0" && WP!=2) continue;
      if(theWP=="0p5" && WP!=3) continue;
      getline(ss,temp,',');
      ptmin = stoi(temp);
      if(pt<=200. && ptmin!=200)     continue;
      else if(pt>=200. && pt<ptmin)  continue;
      getline(ss,temp,',');
      ptmax = stoi(temp);
      if(pt>=800. && ptmax!=800)     continue;
      else if(pt<=800. && pt>ptmax)  continue; 
      getline(ss,temp,',');
      cent = stof(temp);
      getline(ss,temp,',');
      dn = stof(temp);
      getline(ss,temp,',');
      up = stof(temp);
      if(updown==0) SF = cent;
      if(updown >0) SF = cent+up;
      if(updown <0) SF = cent-dn;
      //std::cout << cent << " " << up << " " << dn << std::endl;
      break;
    }
    return SF;
  }

}//namespace sf

