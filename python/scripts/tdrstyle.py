from array import array
import ROOT
ROOT.gROOT.ForceStyle()


## some preferred colors
colors = [ROOT.TColor.GetColor("#73d2de"), ROOT.TColor.GetColor("#218380"), ROOT.TColor.GetColor("#8f2d56"), ROOT.TColor.GetColor("#d81159"), ROOT.TColor.GetColor("#ffbc42")]
colors = [ROOT.TColor.GetColor("#d81159"), ROOT.TColor.GetColor("#ffbc42")]


## DIY palette example
NCont = 99
stops = [ 0.0, 0.20, 0.40, 0.60, 0.80, 1.0]

red = [   (236./255.), (33./255.), (23./255.)  ]
green = [ (228./255.), (191./255.), (127./255.)]
blue = [  (241./255.), (212./255.), (140./255.)]
NRGBs = len(red)

stopsArray = array('d', stops)
redArray = array('d', red)
greenArray = array('d', green)
blueArray = array('d', blue)
ROOT.TColor.CreateGradientColorTable(NRGBs, stopsArray, redArray, greenArray, blueArray, NCont)
ROOT.gStyle.SetNumberContours(NCont)


def tdrGrid( gridOn):
  tdrStyle.SetPadGridX(gridOn)
  tdrStyle.SetPadGridY(gridOn)

#fixOverlay: Redraws the axis
def fixOverlay(): gPad.RedrawAxis()

def setTDRStyle():
  tdrStyle =  ROOT.TStyle("tdrStyle","Style for P-TDR")

  #for the canvas:
  tdrStyle.SetCanvasBorderMode(0)
  tdrStyle.SetCanvasColor(ROOT.kWhite)
  tdrStyle.SetCanvasDefH(600) #Height of canvas
  tdrStyle.SetCanvasDefW(700) #Width of canvas
  tdrStyle.SetCanvasDefX(0)   #POsition on screen
  tdrStyle.SetCanvasDefY(0)


  tdrStyle.SetPadBorderMode(0)
  #tdrStyle.SetPadBorderSize(Width_t size = 1)
  tdrStyle.SetPadColor(ROOT.kWhite)
  tdrStyle.SetPadGridX(False)
  tdrStyle.SetPadGridY(False)
  tdrStyle.SetGridColor(0)
  tdrStyle.SetGridStyle(3)
  tdrStyle.SetGridWidth(1)

  #For the frame:
  tdrStyle.SetFrameBorderMode(0)
  tdrStyle.SetFrameBorderSize(1)
  tdrStyle.SetFrameFillColor(0)
  tdrStyle.SetFrameFillStyle(0)
  tdrStyle.SetFrameLineColor(1)
  tdrStyle.SetFrameLineStyle(1)
  tdrStyle.SetFrameLineWidth(1)
                
  #For the histo:
  tdrStyle.SetHistLineStyle(1)
  tdrStyle.SetHistLineWidth(2)

  tdrStyle.SetEndErrorSize(2)

  tdrStyle.SetMarkerStyle(20)
  tdrStyle.SetMarkerSize(1)

  #For the fit/function:
  tdrStyle.SetOptFit(1)
  tdrStyle.SetFitFormat("5.4g")
  tdrStyle.SetFuncColor(2)
  tdrStyle.SetFuncStyle(1)
  tdrStyle.SetFuncWidth(1)

  #For the date:
  tdrStyle.SetOptDate(0)
  # For the statistics box:
  tdrStyle.SetOptFile(0)
  tdrStyle.SetOptStat(0) # To display the mean and RMS:   SetOptStat("mr")
  tdrStyle.SetStatColor(ROOT.kWhite)
  tdrStyle.SetStatFont(42)
  tdrStyle.SetStatFontSize(0.025)
  tdrStyle.SetStatTextColor(1)
  tdrStyle.SetStatFormat("6.4g")
  tdrStyle.SetStatBorderSize(1)
  tdrStyle.SetStatH(0.1)
  tdrStyle.SetStatW(0.15)

  # Margins:
  tdrStyle.SetPadTopMargin(0.05)
  tdrStyle.SetPadBottomMargin(0.16)
  tdrStyle.SetPadLeftMargin(0.16)
  tdrStyle.SetPadRightMargin(0.12)

  # For the Global title:
  tdrStyle.SetOptTitle(0)
  tdrStyle.SetTitleFont(42)
  tdrStyle.SetTitleColor(1)
  tdrStyle.SetTitleTextColor(1)
  tdrStyle.SetTitleFillColor(10)
  tdrStyle.SetTitleFontSize(0.05)

  # For the axis titles:
  tdrStyle.SetTitleColor(1, "XYZ")
  tdrStyle.SetTitleFont(42, "XYZ")
  tdrStyle.SetTitleSize(0.04, "XYZ")
  tdrStyle.SetTitleXOffset(1.4)
  tdrStyle.SetTitleYOffset(1.7)

  # For the axis labels:
  tdrStyle.SetLabelColor(1, "XYZ")
  tdrStyle.SetLabelFont(42, "XYZ")
  tdrStyle.SetLabelOffset(0.007, "XYZ")
  tdrStyle.SetLabelSize(0.04, "XYZ")

  # For the axis:
  tdrStyle.SetAxisColor(1, "XYZ")
  tdrStyle.SetStripDecimals(True)
  tdrStyle.SetTickLength(0.03, "XYZ")
  tdrStyle.SetNdivisions(510, "XYZ")
  tdrStyle.SetPadTickX(1)  # To get tick marks on the opposite side of the frame
  tdrStyle.SetPadTickY(1)

  # Change for log plots:
  tdrStyle.SetOptLogx(0)
  tdrStyle.SetOptLogy(0)
  tdrStyle.SetOptLogz(0)

  # Postscript options:
  tdrStyle.SetPaperSize(20.,20.)

  tdrStyle.SetHatchesLineWidth(5)
  tdrStyle.SetHatchesSpacing(0.05)

  tdrStyle.SetLegendBorderSize(0)
  tdrStyle.SetLegendFont(42)

  tdrStyle.cd()



# Get maximum of a series of histograms
def getMax(hists):
    ymax = max([h.GetMaximum() for h in hists])
    return ymax
