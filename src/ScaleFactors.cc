
#include "ScaleFactors.h"

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

