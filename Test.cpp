/*
 *
 *
 * Test file
 */
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <dirent.h>

using namespace std;

#include "includes/imageModel/Point.h"
#include "includes/imageModel/Line.h"
#include "includes/imageModel/Edge.h"
#include "includes/imageModel/Matrix.h"
#include "includes/imageModel/Image.h"
#include "includes/utils/Drawing.h"
#include "includes/io/TPSReader.h"
#include "includes/io/Reader.h"

#include "includes/histograms/ShapeHistogram.h"
#include "includes/pht/PHTEntry.h"
#include "includes/pht/PHoughTransform.h"
#include "includes/pht/PCA.h"
#include "includes/correlation/CrossCorrelation.h"
#include "includes/pointInterest/Treatments.h"
#include "includes/pointInterest/Segmentation.h"
#include "includes/pointInterest/GeometricHistgoram.h"
#include "includes/pointInterest/ProHoughTransform.h"
#include "includes/pointInterest/LandmarkDetection.h"

int main(int argc, char* argv[])
{
	cout << "\n MAELab without graphic user interface !!!" << endl;
	string modeljpg, modeltps, scenejpg, scenetps, method, savejpg, savetps;
	int firstSize, secondSize;
	if (argc == 1)
	{
		cout << "\nAutomatic landmarks with SIFT descriptor: " << argv[0] << endl;
		modeljpg = "data/model.JPG";
		modeltps = "data/model.TPS";
		scenejpg = "data/scene2.JPG";
		scenetps = "data/scene2.TPS";
		method = "2"; // 1 is template matching, 2 is SIFT
		firstSize = 9;
		secondSize = 36;
		savejpg = "result.jpg";
		savetps = "result.TPS";
	}
	else
	{
		cout << "\nAutomatic landmarks with SIFT: " << endl;
		modeljpg = argv[1];
		modeltps = argv[2];
		scenejpg = argv[3];
		scenetps = argv[4];
		method = argv[5];
		firstSize = std::atoi(argv[6]);
		secondSize = std::atoi(argv[7]);
		savejpg = argv[8];
		savetps = argv[9];
	}
	vector<Point> estLandmarks;
	Image model(modeljpg);
	model.readManualLandmarks(modeltps);
	Image scene(scenejpg);
	scene.readManualLandmarks(scenetps);

	int rows = scene.getRGBMatrix()->getRows();
	int cols = scene.getRGBMatrix()->getCols();
	estLandmarks = PCAI(model, scene, model.getListOfManualLandmarks());
	RGB color;
	color.R = 255;
	color.G = color.B = 0;
	// draw manual landmarks
	vector<Point> sceneManual = scene.getListOfManualLandmarks();
	Point pi;
	for (size_t i = 0; i < sceneManual.size(); i++)
	{
		pi = sceneManual.at(i);
		fillCircle(*scene.getRGBMatrix(), pi, 3, color);
	}
	// draw estimated landmarks
	color.G = 255;
	for (size_t i = 0; i < estLandmarks.size(); i++)
	{
		pi = estLandmarks.at(i);
		fillCircle(*scene.getRGBMatrix(), pi, 3, color);
	}

	saveRGB(savejpg.c_str(), scene.getRGBMatrix());
	// save TPS
	ofstream inFile(savetps.c_str());
	inFile << "LM=" << estLandmarks.size() << "\n";
	Point epk;
	for (size_t k = 0; k < estLandmarks.size(); k++)
	{
		epk = estLandmarks.at(k);
		Line line(epk, sceneManual.at(k));
		//inFile << epk.getX() << " " << rows - epk.getY() << "\n";
		inFile << epk.getX() << " " << rows - epk.getY() << "\t" << line.getLength()
			<< "\n";
	}
	inFile << "IMAGE=" << savejpg << "\n";
	inFile.close();
	return 0;

}

