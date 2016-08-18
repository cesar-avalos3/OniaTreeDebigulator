void OniaTreeDebigulator()
{
  TString nameOfTree = "hionia/myTree";
  TTree* tree = (TTree*) _file0->Get(nameOfTree);
  TCuts cuts = "";
  tree->Draw(">>eventTemp", cuts, "eventList");
  TEventList* eventList = (TEventList*) gDirectory->Get("eventTemp");
  tree->SetEventList(eventList);
  TFile *out = new TFile("out.root", "RECREATE");
  TTree* smallerTree = tree->Clone("smallerTree");
  smallerTree->Write();
}
