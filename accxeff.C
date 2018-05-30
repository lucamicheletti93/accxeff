#if !defined(__CINT__) || defined(__MAKECINT__)
#include <stdio.h>

#include <TMinuit.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TF1.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TMath.h>
#include <TPad.h>
#include <TSystem.h>
#include <TGraphErrors.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TFitResult.h>
#include <TMatrixDSym.h>
#include <TPaveText.h>
#include <TGaxis.h>
#include <vector.h>
#endif

void accxeff(){

  //============================================================================
  // SETTING MAIN QUANTITIES
  //============================================================================
  bool save_results = kFALSE;
  gStyle -> SetOptStat(0);
  TGaxis::SetMaxDigits(1);
  gSystem -> CompileMacro("../settings.h");
  gROOT -> ProcessLine(".x ../binning.C");

  char INPUT_FILE_NAME[300] = "/home/luca/cernbox/JPSI/JPSI_POLARIZATION/ANALYSIS/TWO_DIM_APPROACH/ACCXEFF/HISTOS_FOR_ACCXEFF/GIT_OUTPUT/HistosFromOfficialTree_Jpsi_PbPb_Nopol.root"; // for ubuntu
  //char INPUT_FILE_NAME[300] = "/Users/Luca/cernbox/JPSI/JPSI_POLARIZATION/ANALYSIS/TWO_DIM_APPROACH/ACCXEFF/HISTOS_FOR_ACCXEFF/GIT_OUTPUT/HistosFromOfficialTree_Jpsi_PbPb_Nopol.root"; // for mac
  printf("Opening %s ... \n",INPUT_FILE_NAME);
  TFile *input_file = new TFile(INPUT_FILE_NAME,"READ");

  char TH2_NAME[50];
  const int Npt_ranges = 12;
  TH2D *hCostPhiHE_2m_gen[Npt_ranges], *hCostPhiHE_2m_rec[Npt_ranges];
  for(int i = 0;i < Npt_ranges;i++){
    sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_gen",i,i+1);
    hCostPhiHE_2m_gen[i] = (TH2D*) input_file -> Get(TH2_NAME);
    sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_rec",i,i+1);
    hCostPhiHE_2m_rec[i] = (TH2D*) input_file -> Get(TH2_NAME);
  }

  //============================================================================
  printf("Defining the pT ranges ... \n");
  //============================================================================
  for(int i = 0;i < N_pt_bin;i++){printf("[%i < pT < %i GeV/c]",min_pt_bin[i],max_pt_bin[i]);}
  printf("\n");

  // Generated
  sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_gen",min_pt_bin[0],max_pt_bin[0]);
  TH2D *hCostPhiHE_0pt2_2m_gen = (TH2D*) hCostPhiHE_2m_gen[0] -> Clone(); // 0 < pT < 1 GeV/c
  hCostPhiHE_0pt2_2m_gen -> SetTitle(TH2_NAME);
  hCostPhiHE_0pt2_2m_gen -> Add(hCostPhiHE_2m_gen[1]); // 1 < pT < 2 GeV/c

  sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_gen",min_pt_bin[1],max_pt_bin[1]);
  TH2D *hCostPhiHE_2pt6_2m_gen = (TH2D*) hCostPhiHE_2m_gen[2] -> Clone(); // 2 < pT < 3 GeV/c
  hCostPhiHE_2pt6_2m_gen -> SetTitle(TH2_NAME);
  hCostPhiHE_2pt6_2m_gen -> Add(hCostPhiHE_2m_gen[3]); // 3 < pT < 4 GeV/c
  hCostPhiHE_2pt6_2m_gen -> Add(hCostPhiHE_2m_gen[4]); // 4 < pT < 5 GeV/c
  hCostPhiHE_2pt6_2m_gen -> Add(hCostPhiHE_2m_gen[5]); // 5 < pT < 6 GeV/c

  sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_gen",min_pt_bin[2],max_pt_bin[2]);
  TH2D *hCostPhiHE_6pt12_2m_gen = (TH2D*) hCostPhiHE_2m_gen[6] -> Clone(); // 6 < pT < 7 GeV/c
  hCostPhiHE_6pt12_2m_gen -> SetTitle(TH2_NAME);
  hCostPhiHE_6pt12_2m_gen -> Add(hCostPhiHE_2m_gen[7]); // 7 < pT < 8 GeV/c
  hCostPhiHE_6pt12_2m_gen -> Add(hCostPhiHE_2m_gen[8]); // 8 < pT < 9 GeV/c
  hCostPhiHE_6pt12_2m_gen -> Add(hCostPhiHE_2m_gen[9]); // 9 < pT < 10 GeV/c
  hCostPhiHE_6pt12_2m_gen -> Add(hCostPhiHE_2m_gen[10]); // 10 < pT < 11 GeV/c
  hCostPhiHE_6pt12_2m_gen -> Add(hCostPhiHE_2m_gen[11]); // 11 < pT < 12 GeV/c

  // Reconstructed
  sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_rec",min_pt_bin[0],max_pt_bin[0]);
  TH2D *hCostPhiHE_0pt2_2m_rec = (TH2D*) hCostPhiHE_2m_rec[0] -> Clone(); // 0 < pT < 1 GeV/c
  hCostPhiHE_0pt2_2m_rec -> SetTitle(TH2_NAME);
  hCostPhiHE_0pt2_2m_rec -> Add(hCostPhiHE_2m_rec[1]); // 1 < pT < 2 GeV/c

  sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_rec",min_pt_bin[1],max_pt_bin[1]);
  TH2D *hCostPhiHE_2pt6_2m_rec = (TH2D*) hCostPhiHE_2m_rec[2] -> Clone(); // 2 < pT < 3 GeV/c
  hCostPhiHE_2pt6_2m_rec -> SetTitle(TH2_NAME);
  hCostPhiHE_2pt6_2m_rec -> Add(hCostPhiHE_2m_rec[3]); // 3 < pT < 4 GeV/c
  hCostPhiHE_2pt6_2m_rec -> Add(hCostPhiHE_2m_rec[4]); // 4 < pT < 5 GeV/c
  hCostPhiHE_2pt6_2m_rec -> Add(hCostPhiHE_2m_rec[5]); // 5 < pT < 6 GeV/c

  sprintf(TH2_NAME,"hCostPhiHE_%ipt%i_2m_rec",min_pt_bin[2],max_pt_bin[2]);
  TH2D *hCostPhiHE_6pt12_2m_rec = (TH2D*) hCostPhiHE_2m_rec[6] -> Clone(); // 6 < pT < 7 GeV/c
  hCostPhiHE_6pt12_2m_rec -> SetTitle(TH2_NAME);
  hCostPhiHE_6pt12_2m_rec -> Add(hCostPhiHE_2m_rec[7]); // 7 < pT < 8 GeV/c
  hCostPhiHE_6pt12_2m_rec -> Add(hCostPhiHE_2m_rec[8]); // 8 < pT < 9 GeV/c
  hCostPhiHE_6pt12_2m_rec -> Add(hCostPhiHE_2m_rec[9]); // 9 < pT < 10 GeV/c
  hCostPhiHE_6pt12_2m_rec -> Add(hCostPhiHE_2m_rec[10]); // 10 < pT < 11 GeV/c
  hCostPhiHE_6pt12_2m_rec -> Add(hCostPhiHE_2m_rec[11]); // 11 < pT < 12 GeV/c

  //============================================================================
  printf("Creating the TH2D with the binning tuned on data ... \n");
  //============================================================================

  TH2D *hist_CostPhiHE_0pt2_gen_rebin = new TH2D("hist_CostPhiHE_0pt2_gen_rebin","hist_CostPhiHE_0pt2_gen_rebin",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_2pt6_gen_rebin = new TH2D("hist_CostPhiHE_2pt6_gen_rebin","hist_CostPhiHE_2pt6_gen_rebin",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_6pt12_gen_rebin = new TH2D("hist_CostPhiHE_6pt12_gen_rebin","hist_CostPhiHE_6pt12_gen_rebin",N_cost_bins,value_cost,N_phi_bins,value_phi);

  TH2D *hist_CostPhiHE_0pt2_rec_rebin = new TH2D("hist_CostPhiHE_0pt2_rec_rebin","hist_CostPhiHE_0pt2_rec_rebin",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_2pt6_rec_rebin = new TH2D("hist_CostPhiHE_2pt6_rec_rebin","hist_CostPhiHE_2pt6_rec_rebin",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_6pt12_rec_rebin = new TH2D("hist_CostPhiHE_6pt12_rec_rebin","hist_CostPhiHE_6pt12_rec_rebin",N_cost_bins,value_cost,N_phi_bins,value_phi);

  for(int i = 0;i < N_cost_bins;i++){
    for(int j = 0;j < N_phi_bins;j++){
      hist_CostPhiHE_0pt2_gen_rebin -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_gen -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_2pt6_gen_rebin -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_gen -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_6pt12_gen_rebin -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_gen -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));

      hist_CostPhiHE_0pt2_rec_rebin -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_rec -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_2pt6_rec_rebin -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_rec -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_6pt12_rec_rebin -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_rec -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
    }
  }

  //============================================================================
  printf("Computing Acc X Eff ... \n");
  //============================================================================

  hist_CostPhiHE_0pt2_rec_rebin -> Sumw2();
  hist_CostPhiHE_0pt2_gen_rebin -> Sumw2();
  hist_CostPhiHE_2pt6_rec_rebin -> Sumw2();
  hist_CostPhiHE_2pt6_gen_rebin -> Sumw2();
  hist_CostPhiHE_6pt12_rec_rebin -> Sumw2();
  hist_CostPhiHE_6pt12_gen_rebin -> Sumw2();

  TH2D *hist_accxeff_HE_0pt2_rebin = new TH2D("hist_accxeff_HE_0pt2_rebin","",N_cost_bins,value_cost,N_phi_bins,value_phi);
  hist_accxeff_HE_0pt2_rebin -> Divide(hist_CostPhiHE_0pt2_rec_rebin,hist_CostPhiHE_0pt2_gen_rebin,1,1,"B");

  TH2D *hist_accxeff_HE_2pt6_rebin = new TH2D("hist_accxeff_HE_2pt6_rebin","",N_cost_bins,value_cost,N_phi_bins,value_phi);
  hist_accxeff_HE_2pt6_rebin -> Divide(hist_CostPhiHE_2pt6_rec_rebin,hist_CostPhiHE_2pt6_gen_rebin,1,1,"B");

  TH2D *hist_accxeff_HE_6pt12_rebin = new TH2D("hist_accxeff_HE_6pt12_rebin","",N_cost_bins,value_cost,N_phi_bins,value_phi);
  hist_accxeff_HE_6pt12_rebin -> Divide(hist_CostPhiHE_6pt12_rec_rebin,hist_CostPhiHE_6pt12_gen_rebin,1,1,"B");

  //============================================================================
  printf("Saving Acc X Eff ... \n");
  //============================================================================

  char OUTPUT_FILE_NAME[300] = "/home/luca/cernbox/JPSI/JPSI_POLARIZATION/ANALYSIS/TWO_DIM_APPROACH/ACCXEFF/HISTOS_FOR_ACCXEFF/GIT_OUTPUT/accxeff.root"; // for ubuntu
  //char OUTPUT_FILE_NAME[300] = "/Users/Luca/cernbox/JPSI/JPSI_POLARIZATION/ANALYSIS/TWO_DIM_APPROACH/ACCXEFF/HISTOS_FOR_ACCXEFF/GIT_OUTPUT/accxeff.root"; // for mac
  printf("saving in %s ... \n",OUTPUT_FILE_NAME);
  TFile *output_file = new TFile(OUTPUT_FILE_NAME,"RECREATE");
  hist_accxeff_HE_0pt2_rebin -> Write();
  hist_accxeff_HE_2pt6_rebin -> Write();
  hist_accxeff_HE_6pt12_rebin -> Write();
}
