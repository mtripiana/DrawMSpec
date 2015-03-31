#include <TLine.h>
#include <TH2F.h>

#define bwidth 1.1   // bin width 
#define lwidth 0.9   // line width 

void SetStyle()
{
	gStyle->SetPalette(1);
	gStyle->SetFrameFillColor(0);
	gStyle->SetFrameBorderSize(0);
	gStyle->SetFrameBorderMode(0);
	gStyle->SetCanvasColor(0);
	gStyle->SetOptStat(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(0);
	gStyle->SetTextFont(42);
	gStyle->SetLabelFont(42,"XY");
	gStyle->SetTitleFont(42,"XY");
	gStyle->SetEndErrorSize(0);
}
	
TLine* GetLine(float mass, int number=1, int color=1){

	float xmin=number*bwidth;
	float shift=(bwidth-lwidth)/2.;
	
	TLine* line = new TLine(xmin+shift,mass,xmin+bwidth-shift,mass);
	line->SetLineWidth(3);
	line->SetLineColor(color);
	
	return line;
}

TLatex* GetLabel(TString text="", float mass=0, int number=1){

	TLatex* mytext = new TLatex(number*bwidth+0.15, mass*1.75, text); 
	mytext->SetTextSize(0.02);

	return mytext;	
}

void DrawMassSpectrum(float M_chi10=-9999,
		      float M_chi20=-9999,
		      float M_chi30=-9999,
		      float M_chi40=-9999,
		      float M_chi1p=-9999,
		      float M_chi2p=-9999,
		      float M_uL=-9999,
		      float M_uR=-9999,
		      float M_dL=-9999,
		      float M_dR=-9999,
		      float M_sL=-9999,
		      float M_sR=-9999,
		      float M_cL=-9999,
		      float M_cR=-9999,
		      float M_t1=-9999,
		      float M_t2=-9999,
		      float M_b1=-9999,
		      float M_b2=-9999,
		      float M_eL=-9999,
		      float M_eR=-9999,
		      float M_nu_eL=-9999, 
		      float M_muL=-9999,
		      float M_muR=-9999,
		      float M_nu_muL=-9999, 
		      float M_tau1=-9999,
		      float M_tau2=-9999,
		      float M_nu_tauL=-9999,
		      float M_h0=-9999,
		      float M_H=-9999,
		      float M_Hp=-9999,
		      float M_A=-9999,
		      float M_gl=-9999,
		      float M_G=-9999,
		      float MIN=-9999,
		      float MAX=-9999,
		      TString tag="",
		      TString format="eps",
		      TString outdir="./")
{
  cout << "GENERATING MASS SPECTRUM..." << endl;
  
  SetStyle();
		
  int color1 = kRed;	
  int color2 = kOrange;	
  int color3 = kGreen;	
  int color4 = kBlue;
  int color5 = kCyan+1;
  int color6 = kMagenta+1;	
  int color7 = kBlack;	
		
  //Get Lines 
  int N=0;	
  TLine* L_gl      = GetLine(M_gl     ,  N+=1,  color6);
  TLine* L_G       = GetLine(M_G      ,  N+=1,  color7);
  TLine* L_h0      = GetLine(M_h0     ,  N+=1,  color5);
  TLine* L_H       = GetLine(M_H      ,  N+=1,  color5);
  TLine* L_Hp      = GetLine(M_Hp     ,  N+=1,  color5);
  TLine* L_A       = GetLine(M_A      ,  N+=1,  color5);
  TLine* L_chi10   = GetLine(M_chi10  ,  N+=1,  color1);
  TLine* L_chi20   = GetLine(M_chi20  ,  N+=1,  color1);
  TLine* L_chi30   = GetLine(M_chi30  ,  N+=1,  color1);
  TLine* L_chi40   = GetLine(M_chi40  ,  N+=1,  color1);
  TLine* L_chi1p   = GetLine(M_chi1p  ,  N+=1,  color2);
  TLine* L_chi2p   = GetLine(M_chi2p  ,  N+=1,  color2);
  TLine* L_uL      = GetLine(M_uL     ,  N+=1,  color3);
  TLine* L_uR      = GetLine(M_uR     ,  N+=1,  color3);
  TLine* L_dL      = GetLine(M_dL     ,  N+=1,  color3);
  TLine* L_dR      = GetLine(M_dR     ,  N+=1,  color3);
  TLine* L_sL      = GetLine(M_sL     ,  N+=1,  color3);
  TLine* L_sR      = GetLine(M_sR     ,  N+=1,  color3);
  TLine* L_cL      = GetLine(M_cL     ,  N+=1,  color3);
  TLine* L_cR      = GetLine(M_cR     ,  N+=1,  color3);
  TLine* L_t1      = GetLine(M_t1     ,  N+=1,  color3);
  TLine* L_t2      = GetLine(M_t2     ,  N+=1,  color3);
  TLine* L_b1      = GetLine(M_b1     ,  N+=1,  color3);
  TLine* L_b2      = GetLine(M_b2     ,  N+=1,  color3);
  TLine* L_eL      = GetLine(M_eL     ,  N+=1,  color4);
  TLine* L_eR      = GetLine(M_eR     ,  N+=1,  color4);
  TLine* L_nu_eL   = GetLine(M_nu_eL  ,  N+=1,  color4);
  TLine* L_muL     = GetLine(M_muL    ,  N+=1,  color4);
  TLine* L_muR     = GetLine(M_muR    ,  N+=1,  color4);
  TLine* L_nu_muL  = GetLine(M_nu_muL ,  N+=1,  color4);
  TLine* L_tau1    = GetLine(M_tau1   ,  N+=1,  color4);
  TLine* L_tau2    = GetLine(M_tau2   ,  N+=1,  color4);
  TLine* L_nu_tauL = GetLine(M_nu_tauL,  N+=1,  color4);

  //Get Labels
  N=0;
  TLatex* T_gl      = GetLabel("#tilde{g}",           M_gl     ,  N+=1);
  TLatex* T_G       = GetLabel("#tilde{G}",           M_G      ,  N+=1);
  TLatex* T_h0      = GetLabel("h",                   M_h0     ,  N+=1);
  TLatex* T_H       = GetLabel("H",                   M_H      ,  N+=1);
  TLatex* T_Hp      = GetLabel("H^{+}",               M_Hp     ,  N+=1);
  TLatex* T_A       = GetLabel("A",                   M_A      ,  N+=1);
  TLatex* T_chi10   = GetLabel("#chi^{0}_{1}",        M_chi10  ,  N+=1);
  TLatex* T_chi20   = GetLabel("#chi^{0}_{2}",        M_chi20  ,  N+=1);
  TLatex* T_chi30   = GetLabel("#chi^{0}_{3}",        M_chi30  ,  N+=1);
  TLatex* T_chi40   = GetLabel("#chi^{0}_{4}",        M_chi40  ,  N+=1);
  TLatex* T_chi1p   = GetLabel("#chi^{+}_{1}",        M_chi1p  ,  N+=1);
  TLatex* T_chi2p   = GetLabel("#chi^{+}_{2}",        M_chi2p  ,  N+=1);
  TLatex* T_uL      = GetLabel("#tilde{u}_{L}",       M_uL     ,  N+=1);
  TLatex* T_uR      = GetLabel("#tilde{u}_{R}",       M_uR     ,  N+=1);
  TLatex* T_dL      = GetLabel("#tilde{d}_{L}",       M_dL     ,  N+=1);
  TLatex* T_dR      = GetLabel("#tilde{d}_{R}",       M_dR     ,  N+=1);
  TLatex* T_sL      = GetLabel("#tilde{s}_{L}",       M_sL     ,  N+=1);
  TLatex* T_sR      = GetLabel("#tilde{s}_{R}",       M_sR     ,  N+=1);
  TLatex* T_cL      = GetLabel("#tilde{c}_{L}",       M_cL     ,  N+=1);
  TLatex* T_cR      = GetLabel("#tilde{c}_{R}",       M_cR     ,  N+=1);
  TLatex* T_t1      = GetLabel("#tilde{t}_{1}",       M_t1     ,  N+=1);
  TLatex* T_t2      = GetLabel("#tilde{t}_{2}",       M_t2     ,  N+=1);
  TLatex* T_b1      = GetLabel("#tilde{b}_{1}",       M_b1     ,  N+=1);
  TLatex* T_b2      = GetLabel("#tilde{b}_{2}",       M_b2     ,  N+=1);
  TLatex* T_eL      = GetLabel("#tilde{e}_{L}",       M_eL     ,  N+=1);
  TLatex* T_eR      = GetLabel("#tilde{e}_{R}",       M_eR     ,  N+=1);
  TLatex* T_nu_eL   = GetLabel("#tilde{#nu}_{eL}",    M_nu_eL  ,  N+=1);
  TLatex* T_muL     = GetLabel("#tilde{#mu}_{L}",     M_muL    ,  N+=1);
  TLatex* T_muR     = GetLabel("#tilde{#mu}_{R}",     M_muR    ,  N+=1);
  TLatex* T_nu_muL  = GetLabel("#tilde{#nu}_{#muL}",  M_nu_muL ,  N+=1);
  TLatex* T_tau1    = GetLabel("#tilde{#tau}_{1}",    M_tau1   ,  N+=1);
  TLatex* T_tau2    = GetLabel("#tilde{#tau}_{2}",    M_tau2   ,  N+=1);
  TLatex* T_nu_tauL = GetLabel("#tilde{#nu}_{#tauL}", M_nu_tauL,  N+=1);
	

  //count valid particles
  int Nparts=0;
  if( M_chi10   > 0 )       Nparts++;
  if( M_chi20   > 0 )       Nparts++;
  if( M_chi30   > 0 )       Nparts++;
  if( M_chi40   > 0 )       Nparts++;
  if( M_chi1p   > 0 )       Nparts++;
  if( M_chi2p   > 0 )       Nparts++;
  if( M_uL      > 0 )       Nparts++;
  if( M_uR      > 0 )       Nparts++;
  if( M_dL      > 0 )       Nparts++;
  if( M_dR      > 0 )       Nparts++;
  if( M_sL      > 0 )       Nparts++;
  if( M_sR      > 0 )       Nparts++;
  if( M_cL      > 0 )       Nparts++;
  if( M_cR      > 0 )       Nparts++;
  if( M_t1      > 0 )       Nparts++;
  if( M_t2      > 0 )       Nparts++;
  if( M_b1      > 0 )       Nparts++;
  if( M_b2      > 0 )       Nparts++;
  if( M_eL      > 0 )       Nparts++;
  if( M_eR      > 0 )       Nparts++;
  if( M_nu_eL   > 0 )       Nparts++;
  if( M_muL     > 0 )       Nparts++;
  if( M_muR     > 0 )       Nparts++;
  if( M_nu_muL  > 0 )       Nparts++;
  if( M_tau1    > 0 )       Nparts++;
  if( M_tau2    > 0 )       Nparts++;
  if( M_nu_tauL > 0 )       Nparts++;
  if( M_h0      > 0 )       Nparts++;
  if( M_H       > 0 )       Nparts++;
  if( M_Hp      > 0 )       Nparts++;
  if( M_A       > 0 )       Nparts++;
  if( M_gl      > 0 )       Nparts++;
  if( M_G       > 0 )       Nparts++;
	
  //Draw all spectrum lines
  TCanvas* cmass = new TCanvas("cmass","",800,800);
  cmass->cd()->SetLogy();	
  cmass->cd()->SetLeftMargin(0.14);
  cmass->SetTicks();
	
  TH2F* frame = new TH2F("frame","",1,-1,Nparts+6,100,MIN,MAX);
  frame->GetXaxis()->SetLabelSize(0);
  frame->GetXaxis()->SetTickLength(0);
  frame->GetXaxis()->SetTitle("SUSY PARTICLES");
  frame->GetXaxis()->CenterTitle();
  frame->GetYaxis()->SetTitle("Mass [GeV]");
  frame->GetYaxis()->SetTitleOffset(1.6);
  frame->GetYaxis()->SetRangeUser(MIN, MAX);
	
  frame->Draw();
	
  if( M_chi10   > 0 )   	L_chi10   ->Draw();
  if( M_chi20   > 0 )   	L_chi20   ->Draw();
  if( M_chi30   > 0 )   	L_chi30   ->Draw();
  if( M_chi40   > 0 )   	L_chi40   ->Draw();
  if( M_chi1p   > 0 )   	L_chi1p   ->Draw();
  if( M_chi2p   > 0 )   	L_chi2p   ->Draw();
  if( M_uL      > 0 )   	L_uL      ->Draw();
  if( M_uR      > 0 )   	L_uR      ->Draw();
  if( M_dL      > 0 )   	L_dL      ->Draw();
  if( M_dR      > 0 )   	L_dR      ->Draw();
  if( M_sL      > 0 )   	L_sL      ->Draw();
  if( M_sR      > 0 )   	L_sR      ->Draw();
  if( M_cL      > 0 )   	L_cL      ->Draw();
  if( M_cR      > 0 )   	L_cR      ->Draw();
  if( M_t1      > 0 )   	L_t1      ->Draw();
  if( M_t2      > 0 )   	L_t2      ->Draw();
  if( M_b1      > 0 )   	L_b1      ->Draw();
  if( M_b2      > 0 )   	L_b2      ->Draw();
  if( M_eL      > 0 )   	L_eL      ->Draw();
  if( M_eR      > 0 )   	L_eR      ->Draw();
  if( M_nu_eL   > 0 )   	L_nu_eL   ->Draw();
  if( M_muL     > 0 )   	L_muL     ->Draw();
  if( M_muR     > 0 )   	L_muR     ->Draw();
  if( M_nu_muL  > 0 )   	L_nu_muL  ->Draw();
  if( M_tau1    > 0 )   	L_tau1    ->Draw();
  if( M_tau2    > 0 )   	L_tau2    ->Draw();
  if( M_nu_tauL > 0 )   	L_nu_tauL ->Draw();
  if( M_h0      > 0 )   	L_h0      ->Draw();
  if( M_H       > 0 )   	L_H       ->Draw();
  if( M_Hp      > 0 )   	L_Hp      ->Draw();
  if( M_A       > 0 )   	L_A       ->Draw();
  if( M_gl      > 0 )   	L_gl      ->Draw();
  if( M_G       > 0 )     	L_G       ->Draw();
	         
  if( M_chi10   > 0 )   	T_chi10   ->Draw();
  if( M_chi20   > 0 )   	T_chi20   ->Draw();
  if( M_chi30   > 0 )   	T_chi30   ->Draw();
  if( M_chi40   > 0 )   	T_chi40   ->Draw();
  if( M_chi1p   > 0 )   	T_chi1p   ->Draw();
  if( M_chi2p   > 0 )   	T_chi2p   ->Draw();
  if( M_uL      > 0 )   	T_uL      ->Draw();
  if( M_uR      > 0 )   	T_uR      ->Draw();
  if( M_dL      > 0 )   	T_dL      ->Draw();
  if( M_dR      > 0 )   	T_dR      ->Draw();
  if( M_sL      > 0 )   	T_sL      ->Draw();
  if( M_sR      > 0 )   	T_sR      ->Draw();
  if( M_cL      > 0 )   	T_cL      ->Draw();
  if( M_cR      > 0 )   	T_cR      ->Draw();
  if( M_t1      > 0 )   	T_t1      ->Draw();
  if( M_t2      > 0 )   	T_t2      ->Draw();
  if( M_b1      > 0 )   	T_b1      ->Draw();
  if( M_b2      > 0 )   	T_b2      ->Draw();
  if( M_eL      > 0 )   	T_eL      ->Draw();
  if( M_eR      > 0 )   	T_eR      ->Draw();
  if( M_nu_eL   > 0 )   	T_nu_eL   ->Draw();
  if( M_muL     > 0 )   	T_muL     ->Draw();
  if( M_muR     > 0 )   	T_muR     ->Draw();
  if( M_nu_muL  > 0 )   	T_nu_muL  ->Draw();
  if( M_tau1    > 0 )   	T_tau1    ->Draw();
  if( M_tau2    > 0 )   	T_tau2    ->Draw();
  if( M_nu_tauL > 0 )   	T_nu_tauL ->Draw();
  if( M_h0      > 0 )   	T_h0      ->Draw();
  if( M_H       > 0 )   	T_H       ->Draw();
  if( M_Hp      > 0 )   	T_Hp      ->Draw();
  if( M_A       > 0 )   	T_A       ->Draw();
  if( M_gl      > 0 )   	T_gl      ->Draw();
  if( M_G       > 0 )     	T_G       ->Draw();
	

  cmass->SaveAs(outdir+"/mass_spectrum"+tag+"."+format);
}

  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
