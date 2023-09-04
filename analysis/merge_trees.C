void doMerge(TString fname);

void merge_trees(){

     TString path = "output_090123_metFix/Run2";
     std::vector<TString> files = {"NonResWWZ.root","ZHWWZ.root","TTZ.root","ZZ.root","WZ.root","Higgs.root","Other.root"};

     for ( auto f : files){
           doMerge(path+"/"+f);
     }
     
}

void doMerge(TString fname){

     TFile *ft = new TFile(fname,"UPDATE");
     TTree *t1 = (TTree*)ft->Get("t_BDT_OF_test");
     TTree *t2 = (TTree*)ft->Get("t_BDT_OF_train");

     TList *list1 = new TList;
     list1->Add(t1);
     list1->Add(t2);

     TTree *t_BDT_OF = TTree::MergeTrees(list1);
     t_BDT_OF->SetName("t_BDT_OF");
     t_BDT_OF->Write();

     TTree *t3 = (TTree*)ft->Get("t_BDT_SF_test");
     TTree *t4 = (TTree*)ft->Get("t_BDT_SF_train");

     TList *list2 = new TList;
     list2->Add(t3);
     list2->Add(t4);

     TTree *t_BDT_SF = TTree::MergeTrees(list2);
     t_BDT_SF->SetName("t_BDT_SF");
     t_BDT_SF->Write();     
       
     ft->Close();
}
