#if !defined(__CINT__) || defined(__MAKECINT__)
#include <stdio.h>

#include <TCanvas.h>
#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TLine.h>
#include <TList.h>
#include <TSystem.h>
#include <TGrid.h>
#include <TString.h>
#include <TStopwatch.h>
#include <TGraphErrors.h>
#include <TMath.h>
#include <TStopwatch.h>
#endif

void create_TH2_from_MCtree(){
  //============================================================================
  //SET ADDRESS
  //============================================================================
  //char *PATH_IN = "READ_MC/OUTPUT/";
  char *PATH_IN = "/home/luca/cernbox/JPSI/JPSI_POLARIZATION/JIRA_TICKET/READ_MC/OUTPUT";
  char FILE_NAME_IN[400];
  sprintf(FILE_NAME_IN,"%s/MC_official_tree_Jpsi_PbPb_Nopol.root",PATH_IN);
  //============================================================================
  //CREATE HISTOGRAMS
  //============================================================================
  double PI = TMath::Pi();

  TH3D *hCostPhiHE_0pt1_2m_gen = new TH3D("hCostPhiHE_0pt1_2m_gen","hCostPhiHE_0pt1_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_1pt2_2m_gen = new TH3D("hCostPhiHE_1pt2_2m_gen","hCostPhiHE_1pt2_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_2pt3_2m_gen = new TH3D("hCostPhiHE_2pt3_2m_gen","hCostPhiHE_2pt3_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_3pt4_2m_gen = new TH3D("hCostPhiHE_3pt4_2m_gen","hCostPhiHE_3pt4_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_4pt5_2m_gen = new TH3D("hCostPhiHE_4pt5_2m_gen","hCostPhiHE_4pt5_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_5pt6_2m_gen = new TH3D("hCostPhiHE_5pt6_2m_gen","hCostPhiHE_5pt6_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_6pt7_2m_gen = new TH3D("hCostPhiHE_6pt7_2m_gen","hCostPhiHE_6pt7_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_7pt8_2m_gen = new TH3D("hCostPhiHE_7pt8_2m_gen","hCostPhiHE_7pt8_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_8pt9_2m_gen = new TH3D("hCostPhiHE_8pt9_2m_gen","hCostPhiHE_8pt9_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_9pt10_2m_gen = new TH3D("hCostPhiHE_9pt10_2m_gen","hCostPhiHE_9pt10_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_10pt11_2m_gen = new TH3D("hCostPhiHE_10pt11_2m_gen","hCostPhiHE_10pt11_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_11pt12_2m_gen = new TH3D("hCostPhiHE_11pt12_2m_gen","hCostPhiHE_11pt12_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_12ptinf_2m_gen = new TH3D("hCostPhiHE_12ptinf_2m_gen","hCostPhiHE_12ptinf_2m_gen",100,-1,1,100,0,PI);

  TH3D *hCostPhiCS_0pt1_2m_gen = new TH3D("hCostPhiCS_0pt1_2m_gen","hCostPhiCS_0pt1_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_1pt2_2m_gen = new TH3D("hCostPhiCS_1pt2_2m_gen","hCostPhiCS_1pt2_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_2pt3_2m_gen = new TH3D("hCostPhiCS_2pt3_2m_gen","hCostPhiCS_2pt3_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_3pt4_2m_gen = new TH3D("hCostPhiCS_3pt4_2m_gen","hCostPhiCS_3pt4_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_4pt5_2m_gen = new TH3D("hCostPhiCS_4pt5_2m_gen","hCostPhiCS_4pt5_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_5pt6_2m_gen = new TH3D("hCostPhiCS_5pt6_2m_gen","hCostPhiCS_5pt6_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_6pt7_2m_gen = new TH3D("hCostPhiCS_6pt7_2m_gen","hCostPhiCS_6pt7_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_7pt8_2m_gen = new TH3D("hCostPhiCS_7pt8_2m_gen","hCostPhiCS_7pt8_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_8pt9_2m_gen = new TH3D("hCostPhiCS_8pt9_2m_gen","hCostPhiCS_8pt9_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_9pt10_2m_gen = new TH3D("hCostPhiCS_9pt10_2m_gen","hCostPhiCS_9pt10_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_10pt11_2m_gen = new TH3D("hCostPhiCS_10pt11_2m_gen","hCostPhiCS_10pt11_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_11pt12_2m_gen = new TH3D("hCostPhiCS_11pt12_2m_gen","hCostPhiCS_11pt12_2m_gen",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_12ptinf_2m_gen = new TH3D("hCostPhiCS_12ptinf_2m_gen","hCostPhiCS_12ptinf_2m_gen",100,-1,1,100,0,PI);

  TH3D *hCostPhiHE_0pt1_2m_rec = new TH3D("hCostPhiHE_0pt1_2m_rec","hCostPhiHE_0pt1_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_1pt2_2m_rec = new TH3D("hCostPhiHE_1pt2_2m_rec","hCostPhiHE_1pt2_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_2pt3_2m_rec = new TH3D("hCostPhiHE_2pt3_2m_rec","hCostPhiHE_2pt3_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_3pt4_2m_rec = new TH3D("hCostPhiHE_3pt4_2m_rec","hCostPhiHE_3pt4_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_4pt5_2m_rec = new TH3D("hCostPhiHE_4pt5_2m_rec","hCostPhiHE_4pt5_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_5pt6_2m_rec = new TH3D("hCostPhiHE_5pt6_2m_rec","hCostPhiHE_5pt6_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_6pt7_2m_rec = new TH3D("hCostPhiHE_6pt7_2m_rec","hCostPhiHE_6pt7_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_7pt8_2m_rec = new TH3D("hCostPhiHE_7pt8_2m_rec","hCostPhiHE_7pt8_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_8pt9_2m_rec = new TH3D("hCostPhiHE_8pt9_2m_rec","hCostPhiHE_8pt9_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_9pt10_2m_rec = new TH3D("hCostPhiHE_9pt10_2m_rec","hCostPhiHE_9pt10_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_10pt11_2m_rec = new TH3D("hCostPhiHE_10pt11_2m_rec","hCostPhiHE_10pt11_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_11pt12_2m_rec = new TH3D("hCostPhiHE_11pt12_2m_rec","hCostPhiHE_11pt12_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiHE_12ptinf_2m_rec = new TH3D("hCostPhiHE_12ptinf_2m_rec","hCostPhiHE_12ptinf_2m_rec",100,-1,1,100,0,PI);

  TH3D *hCostPhiCS_0pt1_2m_rec = new TH3D("hCostPhiCS_0pt1_2m_rec","hCostPhiCS_0pt1_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_1pt2_2m_rec = new TH3D("hCostPhiCS_1pt2_2m_rec","hCostPhiCS_1pt2_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_2pt3_2m_rec = new TH3D("hCostPhiCS_2pt3_2m_rec","hCostPhiCS_2pt3_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_3pt4_2m_rec = new TH3D("hCostPhiCS_3pt4_2m_rec","hCostPhiCS_3pt4_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_4pt5_2m_rec = new TH3D("hCostPhiCS_4pt5_2m_rec","hCostPhiCS_4pt5_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_5pt6_2m_rec = new TH3D("hCostPhiCS_5pt6_2m_rec","hCostPhiCS_5pt6_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_6pt7_2m_rec = new TH3D("hCostPhiCS_6pt7_2m_rec","hCostPhiCS_6pt7_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_7pt8_2m_rec = new TH3D("hCostPhiCS_7pt8_2m_rec","hCostPhiCS_7pt8_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_8pt9_2m_rec = new TH3D("hCostPhiCS_8pt9_2m_rec","hCostPhiCS_8pt9_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_9pt10_2m_rec = new TH3D("hCostPhiCS_9pt10_2m_rec","hCostPhiCS_9pt10_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_10pt11_2m_rec = new TH3D("hCostPhiCS_10pt11_2m_rec","hCostPhiCS_10pt11_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_11pt12_2m_rec = new TH3D("hCostPhiCS_11pt12_2m_rec","hCostPhiCS_11pt12_2m_rec",100,-1,1,100,0,PI);
  TH3D *hCostPhiCS_12ptinf_2m_rec = new TH3D("hCostPhiCS_12ptinf_2m_rec","hCostPhiCS_12ptinf_2m_rec",100,-1,1,100,0,PI);
  //============================================================================
  //OPENING THE FILE
  //============================================================================
  TChain *chain = new TChain("MCTree");

  Long_t *dummy1 = 0, *dummy2 = 0, *dummy3 = 0, *dummy4 = 0;
  if(gSystem -> GetPathInfo(FILE_NAME_IN,dummy1,dummy2,dummy3,dummy4) != 0){
    printf("NOT EXISTING FILE\n");
    return;
  }

  printf("Opening %s\n",FILE_NAME_IN);
  chain -> Add(FILE_NAME_IN);
  //============================================================================
  //SET TREE VARIABLES -> GENERATION
  //============================================================================
  //TStopwatch *clock1 = new TStopwatch();
  //clock1 -> Start();

  Int_t NDimu_gen;
  Double_t DimuPt_gen[3000], DimuY_gen[3000];
  Double_t CostHE_gen[3000], PhiHE_gen[3000], CostCS_gen[3000], PhiCS_gen[3000];

  chain -> SetBranchAddress("NDimu_gen",&NDimu_gen);
  chain -> SetBranchAddress("DimuPt_gen",DimuPt_gen);
  chain -> SetBranchAddress("DimuY_gen",DimuY_gen);
  chain -> SetBranchAddress("CostHE_gen",CostHE_gen);
  chain -> SetBranchAddress("PhiHE_gen",PhiHE_gen);
  chain -> SetBranchAddress("CostCS_gen",CostCS_gen);
  chain -> SetBranchAddress("PhiCS_gen",PhiCS_gen);
  //============================================================================
  //FILLING HISTOS
  //============================================================================
  Int_t NEntries = chain -> GetEntries();
  for(int i = 0;i < NEntries;i++){
    printf("GENERATED %i -> %i : %3.2f%\r",NEntries,i,(double) i/NEntries*100);
    chain -> GetEntry(i);
    for(int k = 0;k < NDimu_gen;k++){
      if(DimuY_gen[k] > -4. && DimuY_gen[k] < -2.5){
          if(DimuPt_gen[k] > 0 && DimuPt_gen[k] <= 1){hCostPhiHE_0pt1_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_0pt1_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 1 && DimuPt_gen[k] <= 2){hCostPhiHE_1pt2_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_1pt2_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 2 && DimuPt_gen[k] <= 3){hCostPhiHE_2pt3_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_2pt3_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 3 && DimuPt_gen[k] <= 4){hCostPhiHE_3pt4_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_3pt4_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 4 && DimuPt_gen[k] <= 5){hCostPhiHE_4pt5_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_4pt5_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 5 && DimuPt_gen[k] <= 6){hCostPhiHE_5pt6_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_5pt6_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 6 && DimuPt_gen[k] <= 7){hCostPhiHE_6pt7_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_6pt7_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 7 && DimuPt_gen[k] <= 8){hCostPhiHE_7pt8_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_7pt8_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 8 && DimuPt_gen[k] <= 9){hCostPhiHE_8pt9_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_8pt9_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 9 && DimuPt_gen[k] <= 10){hCostPhiHE_9pt10_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_9pt10_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 10 && DimuPt_gen[k] <= 11){hCostPhiHE_10pt11_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_10pt11_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 11 && DimuPt_gen[k] <= 12){hCostPhiHE_11pt12_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_11pt12_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
          if(DimuPt_gen[k] > 12){hCostPhiHE_12ptinf_2m_gen -> Fill(CostHE_gen[k],TMath::Abs(PhiHE_gen[k])); hCostPhiCS_12ptinf_2m_gen -> Fill(CostCS_gen[k],TMath::Abs(PhiCS_gen[k]));}
        }
      }
    }
    printf("\n");
    //clock1 -> Stop();
    //clock1 -> Print();

    //==========================================================================
    //SET TREE VARIABLES -> RECONSTRUCTION
    //==========================================================================
    //TStopwatch *clock2 = new TStopwatch();
    //clock2 -> Start();

    Int_t NDimu_rec;
    Double_t DimuPt_rec[3000], DimuY_rec[3000];
    Double_t DimuMass_rec[3000];
    Int_t DimuMatch_rec[3000];
    Double_t CostHE_rec[3000], PhiHE_rec[3000], CostCS_rec[3000], PhiCS_rec[3000];
    //Bool_t IsPhysSelected;

    //chain -> SetBranchAddress("FiredTriggerClasses",TrigClass); //???
    chain -> SetBranchAddress("NDimu_rec",&NDimu_rec);
    chain -> SetBranchAddress("DimuPt_rec",DimuPt_rec);
    chain -> SetBranchAddress("DimuY_rec",DimuY_rec);
    chain -> SetBranchAddress("DimuMass_rec",DimuMass_rec);
    chain -> SetBranchAddress("DimuMatch_rec",DimuMatch_rec);
    chain -> SetBranchAddress("CostHE_rec",CostHE_rec);
    chain -> SetBranchAddress("PhiHE_rec",PhiHE_rec);
    chain -> SetBranchAddress("CostCS_rec",CostCS_rec);
    chain -> SetBranchAddress("PhiCS_rec",PhiCS_rec);
    //chain -> SetBranchAddress("IsPhysSelected",&IsPhysSelected); //???

    //============================================================================
    //FILLING HISTOS
    //============================================================================
    NEntries = chain -> GetEntries();
    for(int i = 0;i < NEntries;i++){
      printf("RECONSTRUCTED %i -> %i : %3.2f%\r",NEntries,i,(double) i/NEntries*100);
      chain -> GetEntry(i);
      for(int k = 0;k < NDimu_rec;k++){

        //if(IsPhysSelected){
          //TString Trigger = TrigClass;
          //Bool_t TriggerSelected = kFALSE;
          //if(Trigger.Contains("CMUL7-B-NOPF-MUFAST")) TriggerSelected = kTRUE;
          if(DimuY_rec[k] > -4. && DimuY_rec[k] < -2.5){
            //if(TriggerSelected){
              if(DimuMatch_rec[k] == 2){
                if(DimuMass_rec[k] > 2 && DimuMass_rec[k] < 5){
                  if(DimuPt_rec[k] > 0 && DimuPt_rec[k] <= 1){hCostPhiHE_0pt1_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_0pt1_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 1 && DimuPt_rec[k] <= 2){hCostPhiHE_1pt2_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_1pt2_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 2 && DimuPt_rec[k] <= 3){hCostPhiHE_2pt3_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_2pt3_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 3 && DimuPt_rec[k] <= 4){hCostPhiHE_3pt4_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_3pt4_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 4 && DimuPt_rec[k] <= 5){hCostPhiHE_4pt5_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_4pt5_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 5 && DimuPt_rec[k] <= 6){hCostPhiHE_5pt6_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_5pt6_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 6 && DimuPt_rec[k] <= 7){hCostPhiHE_6pt7_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_6pt7_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 7 && DimuPt_rec[k] <= 8){hCostPhiHE_7pt8_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_7pt8_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 8 && DimuPt_rec[k] <= 9){hCostPhiHE_8pt9_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_8pt9_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 9 && DimuPt_rec[k] <= 10){hCostPhiHE_9pt10_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_9pt10_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 10 && DimuPt_rec[k] <= 11){hCostPhiHE_10pt11_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_10pt11_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 11 && DimuPt_rec[k] <= 12){hCostPhiHE_11pt12_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_11pt12_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                  if(DimuPt_rec[k] > 12){hCostPhiHE_12ptinf_2m_rec -> Fill(CostHE_rec[k],TMath::Abs(PhiHE_rec[k])); hCostPhiCS_12ptinf_2m_rec -> Fill(CostCS_rec[k],TMath::Abs(PhiCS_rec[k]));}
                }
              }
            //}
          }
        //}
      }
    }

    printf("\n");
    //clock2 -> Stop();
    //clock2 -> Print();

    //============================================================================
    //SAVE FILES
    //============================================================================

    //char *PATH_OUT = "READING_MC/OUTPUT_TREE/OUTPUT_TH3";
    char FILE_NAME_OUT[400];
    sprintf(FILE_NAME_OUT,"/home/luca/cernbox/JPSI/JPSI_POLARIZATION/ANALYSIS/TWO_DIM_APPROACH/ACCXEFF/HISTOS_FOR_ACCXEFF/GIT_OUTPUT/HistosFromOfficialTree_Jpsi_PbPb_Nopol.root");
    TFile *file_out = new TFile(FILE_NAME_OUT,"RECREATE");
    file_out -> cd();
    hCostPhiHE_0pt1_2m_gen -> Write();
    hCostPhiHE_1pt2_2m_gen -> Write();
    hCostPhiHE_2pt3_2m_gen -> Write();
    hCostPhiHE_3pt4_2m_gen -> Write();
    hCostPhiHE_4pt5_2m_gen -> Write();
    hCostPhiHE_5pt6_2m_gen -> Write();
    hCostPhiHE_6pt7_2m_gen -> Write();
    hCostPhiHE_7pt8_2m_gen -> Write();
    hCostPhiHE_8pt9_2m_gen -> Write();
    hCostPhiHE_9pt10_2m_gen -> Write();
    hCostPhiHE_10pt11_2m_gen -> Write();
    hCostPhiHE_11pt12_2m_gen -> Write();
    hCostPhiHE_12ptinf_2m_gen -> Write();

    hCostPhiCS_0pt1_2m_gen -> Write();
    hCostPhiCS_1pt2_2m_gen -> Write();
    hCostPhiCS_2pt3_2m_gen -> Write();
    hCostPhiCS_3pt4_2m_gen -> Write();
    hCostPhiCS_4pt5_2m_gen -> Write();
    hCostPhiCS_5pt6_2m_gen -> Write();
    hCostPhiCS_6pt7_2m_gen -> Write();
    hCostPhiCS_7pt8_2m_gen -> Write();
    hCostPhiCS_8pt9_2m_gen -> Write();
    hCostPhiCS_9pt10_2m_gen -> Write();
    hCostPhiCS_10pt11_2m_gen -> Write();
    hCostPhiCS_11pt12_2m_gen -> Write();
    hCostPhiCS_12ptinf_2m_gen -> Write();

    hCostPhiHE_0pt1_2m_rec -> Write();
    hCostPhiHE_1pt2_2m_rec -> Write();
    hCostPhiHE_2pt3_2m_rec -> Write();
    hCostPhiHE_3pt4_2m_rec -> Write();
    hCostPhiHE_4pt5_2m_rec -> Write();
    hCostPhiHE_5pt6_2m_rec -> Write();
    hCostPhiHE_6pt7_2m_rec -> Write();
    hCostPhiHE_7pt8_2m_rec -> Write();
    hCostPhiHE_8pt9_2m_rec -> Write();
    hCostPhiHE_9pt10_2m_rec -> Write();
    hCostPhiHE_10pt11_2m_rec -> Write();
    hCostPhiHE_11pt12_2m_rec -> Write();
    hCostPhiHE_12ptinf_2m_rec -> Write();

    hCostPhiCS_0pt1_2m_rec -> Write();
    hCostPhiCS_1pt2_2m_rec -> Write();
    hCostPhiCS_2pt3_2m_rec -> Write();
    hCostPhiCS_3pt4_2m_rec -> Write();
    hCostPhiCS_4pt5_2m_rec -> Write();
    hCostPhiCS_5pt6_2m_rec -> Write();
    hCostPhiCS_6pt7_2m_rec -> Write();
    hCostPhiCS_7pt8_2m_rec -> Write();
    hCostPhiCS_8pt9_2m_rec -> Write();
    hCostPhiCS_9pt10_2m_rec -> Write();
    hCostPhiCS_10pt11_2m_rec -> Write();
    hCostPhiCS_11pt12_2m_rec -> Write();
    hCostPhiCS_12ptinf_2m_rec -> Write();
}
