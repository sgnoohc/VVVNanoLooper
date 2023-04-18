{

   gSystem->AddIncludePath("-I${XGBOOST_PATH}/include");
   gSystem->AddIncludePath("-I${XGBOOST_PATH}/rabit/include");
   gSystem->Load("libCore");
   gSystem->Load("libxgboost");
   gSystem->Load("../NanoTools/NanoCORE/NANO_CORE.so");
   gSystem->Load("../lib_lepton_helpers.so");

}
