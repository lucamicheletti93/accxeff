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

  string PATH = "HISTOS_FOR_ACCXEFF/HistosFromOfficialTree_Jpsi_PbPb_Nopol.root";
  //string PATH = "HISTOS_FOR_ACCXEFF/MC_Histos_full_statistics.root";
  bool save_results = kFALSE;

  //============================================================================
  // SETTING THE BINNING
  //============================================================================

  gSystem -> CompileMacro("../settings.h");
  gROOT -> ProcessLine(".x ../binning.C");

  gStyle -> SetOptStat(0);
  TGaxis::SetMaxDigits(1);

  //============================================================================
  // GETTING THE TH2
  //============================================================================

  TFile *file_TH2_histos = new TFile(PATH.c_str());

  TH2D *hCostPhiHE_0pt2_2m_gen = (TH2D*) file_TH2_histos -> Get("hCostPhiHE_0pt2_2m_gen");
  TH2D *hCostPhiHE_2pt6_2m_gen = (TH2D*) file_TH2_histos -> Get("hCostPhiHE_2pt6_2m_gen");
  TH2D *hCostPhiHE_6pt12_2m_gen = (TH2D*) file_TH2_histos -> Get("hCostPhiHE_6pt12_2m_gen");

  TH2D *hCostPhiHE_0pt2_2m_rec = (TH2D*) file_TH2_histos -> Get("hCostPhiHE_0pt2_2m_rec");
  TH2D *hCostPhiHE_2pt6_2m_rec = (TH2D*) file_TH2_histos -> Get("hCostPhiHE_2pt6_2m_rec");
  TH2D *hCostPhiHE_6pt12_2m_rec = (TH2D*) file_TH2_histos -> Get("hCostPhiHE_6pt12_2m_rec");

  //============================================================================
  // DRAWING ACCXEFF IN THE ORIGINAL BINNING
  //============================================================================

  hCostPhiHE_2pt6_2m_gen -> SetTitle("");
  hCostPhiHE_2pt6_2m_gen -> GetXaxis() -> SetTitle("cos#theta_{HE}");
  hCostPhiHE_2pt6_2m_gen -> GetYaxis() -> SetTitle("#phi_{HE}");

  TCanvas *c_gen_HE_2pt6_original_binning = new TCanvas("c_gen_HE_2pt6_original_binning","c_gen_HE_2pt6_original_binning",4,132,1024,768);
  hCostPhiHE_2pt6_2m_gen -> Draw("COLZ");

  hCostPhiHE_2pt6_2m_rec -> SetTitle("");
  hCostPhiHE_2pt6_2m_rec -> GetXaxis() -> SetTitle("cos#theta_{HE}");
  hCostPhiHE_2pt6_2m_rec -> GetYaxis() -> SetTitle("#phi_{HE}");

  TCanvas *c_rec_HE_2pt6_original_binning = new TCanvas("c_rec_HE_2pt6_original_binning","c_rec_HE_2pt6_original_binning",4,132,1024,768);
  hCostPhiHE_2pt6_2m_rec -> Draw("COLZ");

  TH2D *hist_accxeff_HE_2pt6_original_binning = new TH2D("hist_accxeff_HE_2pt6_original_binning","",100,-1,1,100,-PI,PI);
  hist_accxeff_HE_2pt6_original_binning -> Divide(hCostPhiHE_2pt6_2m_rec,hCostPhiHE_2pt6_2m_gen,1,1,"B");

  TCanvas *c_accxeff_HE_2pt6_original_binning = new TCanvas("c_accxeff_HE_2pt6_original_binning","c_accxeff_HE_2pt6_original_binning",4,132,1024,768);
  hist_accxeff_HE_2pt6_original_binning -> Draw("COLZ");

  //============================================================================
  // BENDING THE HISTOGRAM ALONG PHI
  //============================================================================

  TH2D *hCloneHE_0pt2_gen[2], *hCloneHE_2pt6_gen[2], *hCloneHE_6pt12_gen[2]; // clone gen TH2 in two halves
  TH2D *hCloneHE_0pt2_rec[2], *hCloneHE_2pt6_rec[2], *hCloneHE_6pt12_rec[2]; // clone rec TH2 in two halves

  hCloneHE_0pt2_gen[0] = new TH2D("hCloneHE_0pt2_gen1","hCloneHE_0pt2_gen1",100,-1,1,50,0,PI);
  hCloneHE_0pt2_gen[1] = new TH2D("hCloneHE_0pt2_gen2","hCloneHE_0pt2_gen2",100,-1,1,50,0,PI);
  hCloneHE_2pt6_gen[0] = new TH2D("hCloneHE_2pt6_gen1","hCloneHE_2pt6_gen1",100,-1,1,50,0,PI);
  hCloneHE_2pt6_gen[1] = new TH2D("hCloneHE_2pt6_gen2","hCloneHE_2pt6_gen2",100,-1,1,50,0,PI);
  hCloneHE_6pt12_gen[0] = new TH2D("hCloneHE_6pt12_gen1","hCloneHE_6pt12_gen1",100,-1,1,50,0,PI);
  hCloneHE_6pt12_gen[1] = new TH2D("hCloneHE_6pt12_gen2","hCloneHE_6pt12_gen2",100,-1,1,50,0,PI);

  hCloneHE_0pt2_rec[0] = new TH2D("hCloneHE_0pt2_rec1","hCloneHE_0pt2_rec1",100,-1,1,50,0,PI);
  hCloneHE_0pt2_rec[1] = new TH2D("hCloneHE_0pt2_rec2","hCloneHE_0pt2_rec2",100,-1,1,50,0,PI);
  hCloneHE_2pt6_rec[0] = new TH2D("hCloneHE_2pt6_rec1","hCloneHE_2pt6_rec1",100,-1,1,50,0,PI);
  hCloneHE_2pt6_rec[1] = new TH2D("hCloneHE_2pt6_rec2","hCloneHE_2pt6_rec2",100,-1,1,50,0,PI);
  hCloneHE_6pt12_rec[0] = new TH2D("hCloneHE_6pt12_rec1","hCloneHE_6pt12_rec1",100,-1,1,50,0,PI);
  hCloneHE_6pt12_rec[1] = new TH2D("hCloneHE_6pt12_rec2","hCloneHE_6pt12_rec2",100,-1,1,50,0,PI);

  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 50;j++){
      hCloneHE_0pt2_gen[0] -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_gen -> GetBinContent(i+1,j+51));
      hCloneHE_0pt2_gen[0] -> SetBinError(i+1,j+1,hCostPhiHE_0pt2_2m_gen -> GetBinError(i+1,j+51));
      hCloneHE_0pt2_gen[1] -> SetBinContent(i+1,50-j,hCostPhiHE_0pt2_2m_gen -> GetBinContent(i+1,j+1));
      hCloneHE_0pt2_gen[1] -> SetBinError(i+1,50-j,hCostPhiHE_0pt2_2m_gen -> GetBinError(i+1,j+1));
      hCloneHE_2pt6_gen[0] -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_gen -> GetBinContent(i+1,j+51));
      hCloneHE_2pt6_gen[0] -> SetBinError(i+1,j+1,hCostPhiHE_2pt6_2m_gen -> GetBinError(i+1,j+51));
      hCloneHE_2pt6_gen[1] -> SetBinContent(i+1,50-j,hCostPhiHE_2pt6_2m_gen -> GetBinContent(i+1,j+1));
      hCloneHE_2pt6_gen[1] -> SetBinError(i+1,50-j,hCostPhiHE_2pt6_2m_gen -> GetBinError(i+1,j+1));
      hCloneHE_6pt12_gen[0] -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_gen -> GetBinContent(i+1,j+51));
      hCloneHE_6pt12_gen[0] -> SetBinError(i+1,j+1,hCostPhiHE_6pt12_2m_gen -> GetBinError(i+1,j+51));
      hCloneHE_6pt12_gen[1] -> SetBinContent(i+1,50-j,hCostPhiHE_6pt12_2m_gen -> GetBinContent(i+1,j+1));
      hCloneHE_6pt12_gen[1] -> SetBinError(i+1,50-j,hCostPhiHE_6pt12_2m_gen -> GetBinError(i+1,j+1));

      hCloneHE_0pt2_rec[0] -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_rec -> GetBinContent(i+1,j+51));
      hCloneHE_0pt2_rec[0] -> SetBinError(i+1,j+1,hCostPhiHE_0pt2_2m_rec -> GetBinError(i+1,j+51));
      hCloneHE_0pt2_rec[1] -> SetBinContent(i+1,50-j,hCostPhiHE_0pt2_2m_rec -> GetBinContent(i+1,j+1));
      hCloneHE_0pt2_rec[1] -> SetBinError(i+1,50-j,hCostPhiHE_0pt2_2m_rec -> GetBinError(i+1,j+1));
      hCloneHE_2pt6_rec[0] -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_rec -> GetBinContent(i+1,j+51));
      hCloneHE_2pt6_rec[0] -> SetBinError(i+1,j+1,hCostPhiHE_2pt6_2m_rec -> GetBinError(i+1,j+51));
      hCloneHE_2pt6_rec[1] -> SetBinContent(i+1,50-j,hCostPhiHE_2pt6_2m_rec -> GetBinContent(i+1,j+1));
      hCloneHE_2pt6_rec[1] -> SetBinError(i+1,50-j,hCostPhiHE_2pt6_2m_rec -> GetBinError(i+1,j+1));
      hCloneHE_6pt12_rec[0] -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_rec -> GetBinContent(i+1,j+51));
      hCloneHE_6pt12_rec[0] -> SetBinError(i+1,j+1,hCostPhiHE_6pt12_2m_rec -> GetBinError(i+1,j+51));
      hCloneHE_6pt12_rec[1] -> SetBinContent(i+1,50-j,hCostPhiHE_6pt12_2m_rec -> GetBinContent(i+1,j+1));
      hCloneHE_6pt12_rec[1] -> SetBinError(i+1,50-j,hCostPhiHE_6pt12_2m_rec -> GetBinError(i+1,j+1));
    }
  }

  TH2D *hCostPhiHE_0pt2_2m_gen_phibent = (TH2D*) hCloneHE_0pt2_gen[0] -> Clone("hCostPhiHE_0pt2_2m_gen_phibent"); // bent histogram along phi
  hCostPhiHE_0pt2_2m_gen_phibent -> Add(hCloneHE_0pt2_gen[1]);
  TH2D *hCostPhiHE_2pt6_2m_gen_phibent = (TH2D*) hCloneHE_2pt6_gen[0] -> Clone("hCostPhiHE_2pt6_2m_gen_phibent"); // bent histogram along phi
  hCostPhiHE_2pt6_2m_gen_phibent -> Add(hCloneHE_2pt6_gen[1]);
  TH2D *hCostPhiHE_6pt12_2m_gen_phibent = (TH2D*) hCloneHE_6pt12_gen[0] -> Clone("hCostPhiHE_6pt12_2m_gen_phibent"); // bent histogram along phi
  hCostPhiHE_6pt12_2m_gen_phibent -> Add(hCloneHE_6pt12_gen[1]);
  TH2D *hCostPhiHE_0pt2_2m_rec_phibent = (TH2D*) hCloneHE_0pt2_rec[0] -> Clone("hCostPhiHE_0pt2_2m_rec_phibent"); // bent histogram along phi
  hCostPhiHE_0pt2_2m_rec_phibent -> Add(hCloneHE_0pt2_rec[1]);
  TH2D *hCostPhiHE_2pt6_2m_rec_phibent = (TH2D*) hCloneHE_2pt6_rec[0] -> Clone("hCostPhiHE_2pt6_2m_rec_phibent"); // bent histogram along phi
  hCostPhiHE_2pt6_2m_rec_phibent -> Add(hCloneHE_2pt6_rec[1]);
  TH2D *hCostPhiHE_6pt12_2m_rec_phibent = (TH2D*) hCloneHE_6pt12_rec[0] -> Clone("hCostPhiHE_6pt12_2m_rec_phibent"); // bent histogram along phi
  hCostPhiHE_6pt12_2m_rec_phibent -> Add(hCloneHE_6pt12_rec[1]);

  //============================================================================
  // DRAWING ACCXEFF IN THE ORIGINAL BINNING
  //============================================================================

  hCostPhiHE_2pt6_2m_gen_phibent -> SetTitle("");
  hCostPhiHE_2pt6_2m_gen_phibent -> GetXaxis() -> SetTitle("cos#theta_{HE}");
  hCostPhiHE_2pt6_2m_gen_phibent -> GetYaxis() -> SetTitle("#phi_{HE}");

  TCanvas *c_gen_HE_2pt6_phibent = new TCanvas("c_gen_HE_2pt6_phibent","c_gen_HE_2pt6_phibent",4,132,1024,768);
  hCostPhiHE_2pt6_2m_gen_phibent -> Draw("COLZ");

  hCostPhiHE_2pt6_2m_rec_phibent -> SetTitle("");
  hCostPhiHE_2pt6_2m_rec_phibent -> GetXaxis() -> SetTitle("cos#theta_{HE}");
  hCostPhiHE_2pt6_2m_rec_phibent -> GetYaxis() -> SetTitle("#phi_{HE}");

  TCanvas *c_rec_HE_2pt6_phibent = new TCanvas("c_rec_HE_2pt6_phibent","c_rec_HE_2pt6_phibent",4,132,1024,768);
  hCostPhiHE_2pt6_2m_rec_phibent -> Draw("COLZ");

  TH2D *hist_accxeff_HE_2pt6_phibent = new TH2D("hist_accxeff_HE_2pt6_phibent","",100,-1,1,100,-PI,PI);
  hist_accxeff_HE_2pt6_phibent -> Divide(hCostPhiHE_2pt6_2m_rec,hCostPhiHE_2pt6_2m_gen,1,1,"B");
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitle("cos#theta_{HE}");
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitle("#phi_{HE}");

  TCanvas *c_accxeff_HE_2pt6_phibent = new TCanvas("c_accxeff_HE_2pt6_phibent","c_accxeff_HE_2pt6_phibent",4,132,1024,768);
  hist_accxeff_HE_2pt6_phibent -> Draw("COLZ");

  TH2D *hist_accxeff_HE_2pt6_phibent = new TH2D("hist_accxeff_HE_2pt6_phibent","",100,-1,1,50,0,PI);
  hist_accxeff_HE_2pt6_phibent -> Divide(hCostPhiHE_2pt6_2m_rec_phibent,hCostPhiHE_2pt6_2m_gen_phibent,1,1,"B");
  /*hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitle("cos#it{#theta}_{HE}");
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitleSize(0.05);
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitleOffset(0.9);
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitle("#it{#varphi}_{HE}");
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitleSize(0.05);
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitleOffset(0.6);*/
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitle("cos#it{#theta}^{HX}");
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitleSize(0.06);
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetTitleOffset(0.95);
  hist_accxeff_HE_2pt6_phibent -> GetXaxis() -> SetLabelSize(0.05);
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitle("#it{#varphi}^{HX} (rad)");
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitleSize(0.06);
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetTitleOffset(0.85);
  hist_accxeff_HE_2pt6_phibent -> GetYaxis() -> SetLabelSize(0.05);

  TCanvas *c_accxeff_HE_2pt6_phibent = new TCanvas("c_accxeff_HE_2pt6_phibent","c_accxeff_HE_2pt6_phibent",4,132,1100,768);
  c_accxeff_HE_2pt6_phibent -> Range(1.825,-6776.052,5.019444,37862.12);
  c_accxeff_HE_2pt6_phibent -> SetFillColor(0);
  c_accxeff_HE_2pt6_phibent -> SetBorderMode(0);
  c_accxeff_HE_2pt6_phibent -> SetBorderSize(0);
  c_accxeff_HE_2pt6_phibent -> SetTickx(1);
  c_accxeff_HE_2pt6_phibent -> SetTicky(1);
  c_accxeff_HE_2pt6_phibent -> SetLeftMargin(0.18);
  c_accxeff_HE_2pt6_phibent -> SetBottomMargin(0.1518219);
  c_accxeff_HE_2pt6_phibent -> SetFrameBorderMode(0);
  c_accxeff_HE_2pt6_phibent -> SetFrameBorderMode(0);
  hist_accxeff_HE_2pt6_phibent -> Draw("COLZ");

  /*TLegend *leg_Th_Phi = new TLegend(0.58,0.12,0.88,0.30," ","brNDC");
  leg_Th_Phi -> SetTextFont(42);
  leg_Th_Phi -> SetTextSize(0.04);
  leg_Th_Phi -> Draw("same");

  TLatex *lat0 = new TLatex(0.59,0.26,"ALICE Simulation");
  lat0 -> SetTextSize(0.04);
  lat0 -> SetNDC();
  lat0 -> SetTextFont(42);
  lat0 -> Draw("same");

  TLatex *lat1 = new TLatex(0.59,0.20,"Pb-Pb, #sqrt{#it{s}_{NN}} = 5.02 TeV");
  lat1 -> SetTextSize(0.04);
  lat1 -> SetNDC();
  lat1 -> SetTextFont(42);
  lat1 -> Draw("same");

  TLatex *lat2 = new TLatex(0.63,0.14,"Inclusive J/#psi #rightarrow #mu^{+}#mu^{-}");
  lat2 -> SetTextSize(0.04);
  lat2 -> SetNDC();
  lat2 -> SetTextFont(42);
  lat2 -> Draw("same");*/

  TLegend *leg_Th_Phi = new TLegend(0.52,0.16,0.89,0.37," ","brNDC");
  leg_Th_Phi -> SetTextFont(42);
  leg_Th_Phi -> SetTextSize(0.04);
  leg_Th_Phi -> Draw("same");

  TLatex *lat0 = new TLatex(0.53,0.33,"ALICE Simulation");
  lat0 -> SetTextSize(0.04);
  lat0 -> SetNDC();
  lat0 -> SetTextFont(42);
  lat0 -> Draw("same");

  TLatex *lat1 = new TLatex(0.53,0.28,"Pb-Pb, #sqrt{#it{s}_{NN}} = 5.02 TeV");
  lat1 -> SetTextSize(0.04);
  lat1 -> SetNDC();
  lat1 -> SetTextFont(42);
  lat1 -> Draw("same");

  TLatex *lat2 = new TLatex(0.53,0.23,"Inclusive J/#psi #rightarrow #mu^{#plus}#mu^{#minus}");
  lat2 -> SetTextSize(0.04);
  lat2 -> SetNDC();
  lat2 -> SetTextFont(42);
  lat2 -> Draw("same");

  TLatex *lat3 = new TLatex(0.53,0.18,"2 < #it{p}_{T} < 6 GeV/#it{c}, 2.5 < #it{y} < 4");
  lat3 -> SetTextSize(0.04);
  lat3 -> SetNDC();
  lat3 -> SetTextFont(42);
  lat3 -> Draw("same");

  // cheching the results
  //cout << hCostPhiHE_0pt2_2m_gen -> ProjectionY() -> GetBinContent(49) << endl;
  //cout << hCostPhiHE_0pt2_2m_gen -> ProjectionY() -> GetBinContent(52) << endl;
  //cout << hCostPhiHE_0pt2_2m_gen_phibent -> ProjectionY() -> GetBinContent(2) << endl;

  return;

  //============================================================================
  // INIZIALIZING THE TH2 FOR THE ACCXEFF WITH THE CORRECT BINNING
  //============================================================================

  // histograms obtained bending in phi with the new refined binning
  TH2D *hist_CostPhiHE_0pt2_gen_BC = new TH2D("hist_CostPhiHE_0pt2_gen","hist_CostPhiHE_0pt2_gen",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  TH2D *hist_CostPhiHE_2pt6_gen_BC = new TH2D("hist_CostPhiHE_2pt6_gen","hist_CostPhiHE_2pt6_gen",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  TH2D *hist_CostPhiHE_6pt12_gen_BC = new TH2D("hist_CostPhiHE_6pt12_gen","hist_CostPhiHE_6pt12_gen",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  TH2D *hist_CostPhiHE_0pt2_rec_BC = new TH2D("hist_CostPhiHE_0pt2_rec","hist_CostPhiHE_0pt2_rec",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  TH2D *hist_CostPhiHE_2pt6_rec_BC = new TH2D("hist_CostPhiHE_2pt6_rec","hist_CostPhiHE_2pt6_rec",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  TH2D *hist_CostPhiHE_6pt12_rec_BC = new TH2D("hist_CostPhiHE_6pt12_rec","hist_CostPhiHE_6pt12_rec",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);

  for(int i = 0;i < N_cost_bins_BC;i++){
    for(int j = 0;j < N_phi_bins_BC;j++){
      hist_CostPhiHE_0pt2_gen_BC -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_gen_phibent -> Integral(min_cost_bin_BC[i],max_cost_bin_BC[i],min_phi_bin_BC[j],max_phi_bin_BC[j]));
      hist_CostPhiHE_2pt6_gen_BC -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_gen_phibent -> Integral(min_cost_bin_BC[i],max_cost_bin_BC[i],min_phi_bin_BC[j],max_phi_bin_BC[j]));
      hist_CostPhiHE_6pt12_gen_BC -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_gen_phibent -> Integral(min_cost_bin_BC[i],max_cost_bin_BC[i],min_phi_bin_BC[j],max_phi_bin_BC[j]));

      hist_CostPhiHE_0pt2_rec_BC -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_rec_phibent -> Integral(min_cost_bin_BC[i],max_cost_bin_BC[i],min_phi_bin_BC[j],max_phi_bin_BC[j]));
      hist_CostPhiHE_2pt6_rec_BC -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_rec_phibent -> Integral(min_cost_bin_BC[i],max_cost_bin_BC[i],min_phi_bin_BC[j],max_phi_bin_BC[j]));
      hist_CostPhiHE_6pt12_rec_BC -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_rec_phibent -> Integral(min_cost_bin_BC[i],max_cost_bin_BC[i],min_phi_bin_BC[j],max_phi_bin_BC[j]));
    }
  }

  // histograms obtained bending in phi with the old large binning
  TH2D *hist_CostPhiHE_0pt2_2m_gen = new TH2D("hist_CostPhiHE_0pt2_2m_gen","hist_CostPhiHE_0pt2_2m_gen",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_2pt6_2m_gen = new TH2D("hist_CostPhiHE_2pt6_2m_gen","hist_CostPhiHE_2pt6_2m_gen",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_6pt12_2m_gen = new TH2D("hist_CostPhiHE_6pt12_2m_gen","hist_CostPhiHE_6pt12_2m_gen",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_0pt2_2m_rec = new TH2D("hist_CostPhiHE_0pt2_2m_rec","hist_CostPhiHE_0pt2_2m_rec",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_2pt6_2m_rec = new TH2D("hist_CostPhiHE_2pt6_2m_rec","hist_CostPhiHE_2pt6_2m_rec",N_cost_bins,value_cost,N_phi_bins,value_phi);
  TH2D *hist_CostPhiHE_6pt12_2m_rec = new TH2D("hist_CostPhiHE_6pt12_2m_rec","hist_CostPhiHE_6pt12_2m_rec",N_cost_bins,value_cost,N_phi_bins,value_phi);

  for(int i = 0;i < N_cost_bins;i++){
    for(int j = 0;j < N_phi_bins;j++){
      hist_CostPhiHE_0pt2_2m_gen -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_gen_phibent -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_2pt6_2m_gen -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_gen_phibent -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_6pt12_2m_gen -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_gen_phibent -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));

      hist_CostPhiHE_0pt2_2m_rec -> SetBinContent(i+1,j+1,hCostPhiHE_0pt2_2m_rec_phibent -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_2pt6_2m_rec -> SetBinContent(i+1,j+1,hCostPhiHE_2pt6_2m_rec_phibent -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
      hist_CostPhiHE_6pt12_2m_rec -> SetBinContent(i+1,j+1,hCostPhiHE_6pt12_2m_rec_phibent -> Integral(min_cost_bin[i],max_cost_bin[i],min_phi_bin[j],max_phi_bin[j]));
    }
  }

  //============================================================================
  // DRAWING THE TH2
  //============================================================================

  TCanvas *c_gen_rec_BC = new TCanvas("c_gen_rec_BC","c_gen_rec_BC",20,20,600,600);
  c_gen_rec_BC -> Divide(3,2);

  c_gen_rec_BC -> cd(1);
  hist_CostPhiHE_0pt2_gen_BC -> Draw("COLZtext");

  c_gen_rec_BC -> cd(2);
  hist_CostPhiHE_2pt6_gen_BC -> Draw("COLZtext");

  c_gen_rec_BC -> cd(3);
  hist_CostPhiHE_6pt12_gen_BC -> Draw("COLZtext");

  c_gen_rec_BC -> cd(4);
  hist_CostPhiHE_0pt2_rec_BC -> Draw("COLZtext");

  c_gen_rec_BC -> cd(5);
  hist_CostPhiHE_2pt6_rec_BC -> Draw("COLZtext");

  c_gen_rec_BC -> cd(6);
  hist_CostPhiHE_6pt12_rec_BC -> Draw("COLZtext");

  TCanvas *c_gen_rec = new TCanvas("c_gen_rec","c_gen_rec",20,20,600,600);
  c_gen_rec -> Divide(3,2);

  c_gen_rec -> cd(1);
  hist_CostPhiHE_0pt2_2m_gen -> Draw("COLZtext");

  c_gen_rec -> cd(2);
  hist_CostPhiHE_2pt6_2m_gen -> Draw("COLZtext");

  c_gen_rec -> cd(3);
  hist_CostPhiHE_6pt12_2m_gen -> Draw("COLZtext");

  c_gen_rec -> cd(4);
  hist_CostPhiHE_0pt2_2m_rec -> Draw("COLZtext");

  c_gen_rec -> cd(5);
  hist_CostPhiHE_2pt6_2m_rec -> Draw("COLZtext");

  c_gen_rec -> cd(6);
  hist_CostPhiHE_6pt12_2m_rec -> Draw("COLZtext");

  //============================================================================
  // COMPUTE THE ACCXEFF [HELICITY]
  //============================================================================

  hist_CostPhiHE_0pt2_rec_BC -> Sumw2();
  hist_CostPhiHE_0pt2_gen_BC -> Sumw2();

  TH2D *hist_accxeff_HE_0pt2 = new TH2D("hist_accxeff_HE_0pt2","hist_accxeff_HE_0pt2",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  hist_accxeff_HE_0pt2 -> Divide(hist_CostPhiHE_0pt2_rec_BC,hist_CostPhiHE_0pt2_gen_BC,1,1,"B");

  TCanvas *c_accxeff_HE_0pt2 = new TCanvas("c_accxeff_HE_0pt2","c_accxeff_HE_0pt2",4,132,1024,768);
  hist_accxeff_HE_0pt2 -> Draw("COLZtexterror");

  for(int i = 0;i < N_line_cost_BC;i++){
    if(i < N_line_phi_BC) line_phi_BC[i] -> Draw("same");
    line_cost_BC[i] -> Draw("same");
  }

  hist_CostPhiHE_2pt6_rec_BC -> Sumw2();
  hist_CostPhiHE_2pt6_gen_BC -> Sumw2();

  TH2D *hist_accxeff_HE_2pt6 = new TH2D("hist_accxeff_HE_2pt6","hist_accxeff_HE_2pt6",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  hist_accxeff_HE_2pt6 -> Divide(hist_CostPhiHE_2pt6_rec_BC,hist_CostPhiHE_2pt6_gen_BC,1,1,"B");

  TCanvas *c_accxeff_HE_2pt6 = new TCanvas("c_accxeff_HE_2pt6","c_accxeff_HE_2pt6",4,132,1024,768);
  hist_accxeff_HE_2pt6 -> Draw("COLZtexterror");

  for(int i = 0;i < N_line_cost_BC;i++){
    if(i < N_line_phi_BC) line_phi_BC[i] -> Draw("same");
    line_cost_BC[i] -> Draw("same");
  }

  hist_CostPhiHE_6pt12_rec_BC -> Sumw2();
  hist_CostPhiHE_6pt12_gen_BC -> Sumw2();

  TH2D *hist_accxeff_HE_6pt12 = new TH2D("hist_accxeff_HE_6pt12","hist_accxeff_HE_6pt12",N_cost_bins_BC,value_cost_BC,N_phi_bins_BC,value_phi_BC);
  hist_accxeff_HE_6pt12 -> Divide(hist_CostPhiHE_6pt12_rec_BC,hist_CostPhiHE_6pt12_gen_BC,1,1,"B");

  TCanvas *c_accxeff_HE_6pt12 = new TCanvas("c_accxeff_HE_6pt12","c_accxeff_HE_6pt12",4,132,1024,768);
  hist_accxeff_HE_6pt12 -> Draw("COLZtexterror");

  for(int i = 0;i < N_line_cost_BC;i++){
    if(i < N_line_phi_BC) line_phi_BC[i] -> Draw("same");
    line_cost_BC[i] -> Draw("same");
  }

  //============================================================================
  // FILLING THE MATRIX
  //============================================================================

  double accxeff_HE_0pt2[18][10], err_accxeff_HE_0pt2[18][10];
  double accxeff_HE_2pt6[18][10], err_accxeff_HE_2pt6[18][10];
  double accxeff_HE_6pt12[18][10], err_accxeff_HE_6pt12[18][10];

  double rel_err = 0;

  for(int i = 0;i < 18;i++){
    for(int j = 0;j < 10;j++){
      accxeff_HE_0pt2[i][j] = hist_accxeff_HE_0pt2 -> GetBinContent(i+1,j+1);
      err_accxeff_HE_0pt2[i][j] = hist_accxeff_HE_0pt2 -> GetBinError(i+1,j+1);

      accxeff_HE_2pt6[i][j] = hist_accxeff_HE_2pt6 -> GetBinContent(i+1,j+1);
      err_accxeff_HE_2pt6[i][j] = hist_accxeff_HE_2pt6 -> GetBinError(i+1,j+1);
      rel_err = (err_accxeff_HE_2pt6[i][j]/accxeff_HE_2pt6[i][j])*100;
      printf("%4.3f ",rel_err);

      accxeff_HE_6pt12[i][j] = hist_accxeff_HE_6pt12 -> GetBinContent(i+1,j+1);
      err_accxeff_HE_6pt12[i][j] = hist_accxeff_HE_6pt12 -> GetBinError(i+1,j+1);
    }
    printf("\n");
  }

  //============================================================================
  // SAVE RESULTS INTO A TREE
  //============================================================================

  if(save_results){
    TTree *output_tree = new TTree("accxeff","accxeff");
    output_tree -> Branch("accxeff_HE_0pt2",accxeff_HE_0pt2,"accxeff_HE_0pt2[18][10]/D");
    output_tree -> Branch("err_accxeff_HE_0pt2",err_accxeff_HE_0pt2,"err_accxeff_HE_0pt2[18][10]/D");
    output_tree -> Branch("accxeff_HE_2pt6",accxeff_HE_2pt6,"accxeff_HE_2pt6[18][10]/D");
    output_tree -> Branch("err_accxeff_HE_2pt6",err_accxeff_HE_2pt6,"err_accxeff_HE_2pt6[18][10]/D");
    output_tree -> Branch("accxeff_HE_6pt12",accxeff_HE_6pt12,"accxeff_HE_6pt12[18][10]/D");
    output_tree -> Branch("err_accxeff_HE_6pt12",err_accxeff_HE_6pt12,"err_accxeff_HE_6pt12[18][10]/D");
    output_tree -> Fill();

    TFile *output_file = new TFile("../PRELIMINARY/accxeff_FromOfficialTree_Jpsi_PbPb_Nopol.root","RECREATE");
    output_tree -> Write();
    output_file -> Close();
    printf("The file is saved in ../PRELIMINARY \n");
  }

  //TFile *output_accxeff_file = new TFile("../PRELIMINARY/Histo_accxeff_FromOfficialTree_Jpsi_PbPb_Nopol.root","RECREATE");
  //hist_accxeff_HE_2pt6 -> Write();
  //hist_accxeff_HE_2pt6_phibent -> Write();
  //output_accxeff_file -> Close();
}
