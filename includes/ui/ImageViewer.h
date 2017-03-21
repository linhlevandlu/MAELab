/*
 * ImageViewer.h
 *
 *  Created on: Dec 15, 2016
 *      Author: linh
 */

#ifndef IMAGEVIEWER_H_
#define IMAGEVIEWER_H_

#include "../imageModel/Point.h"
#include <QtGui/qlabel.h>
#include <QtGui/qscrollarea.h>
#include <QtGui/QMainWindow>
#include <QtGui/QPrinter>

class Image;

class ImageViewer: public QMainWindow
{
Q_OBJECT
public:
	ImageViewer();
	~ImageViewer();

	QString fileName;
	QImage qImage;
	Image *matImage;

	QAction *parameterAction;
	QDialog *parameterDialog;

	void loadImage(QString fn);
	void loadImage(Image *_matImage, QImage _qImage, QString tt);
private slots:
	void about();
	void testMethod();

	void open();
	void save();
	void saveAs();

	void zoomIn();
	void zoomOut();
	void normalSize();
	void fitToWindow();
	void gScaleHistogram();
	void displayManualLandmarks();
	void displayAutoLandmarks();

	void binThreshold();
	void cannyAlgorithm();
	void suzukiAlgorithm();
	void lineSegmentation();

	//void pHoughTransform();
	void gHoughTransform();
	void extractLandmarks();
	void measureMBary();
	void measureEBary();
	void dirAutoLandmarks();
	void dirCentroidMeasure();
	void dirGenerateData();

	void pcaiMethodViewer();

private:

	QLabel *imageLabel;
	QScrollArea *scrollArea;
	double scaleFactor;

	// menu
	QMenu *fileMenu;
	QMenu *viewMenu;
	QMenu *segmentationMenu;
	QMenu *dominantPointMenu;
	//QMenu *registrationMenu;
	QMenu *helpMenu;

	// toolbar
	QToolBar *fileToolBar;
	QToolBar *viewToolBar;

	//menu action
	QAction *openAct;
	QAction *printAct;
	QAction *saveAct;
	QAction *saveAsAct;
	QAction *closeAct;
	QAction *exitAct;

	QAction *zoomInAct;
	QAction *zoomOutAct;
	QAction *normalSizeAct;
	QAction *fitToWindowAct;
	QAction *gHistogramAct;
	QAction *displayMLandmarksAct;
	QAction *displayALandmarksAct;

	QAction *aboutAct;
	QAction *testAct;

	QAction *binaryThresholdAct;
	QAction *cannyAct;
	QAction *suzukiAct;
	QAction *lineSegmentationAct;

	//QAction *phtAct;
	QAction *phtPointsAct;
	QAction *autoLandmarksAct;
	QAction *measureMBaryAct;
	QAction *measureEBaryAct;
	QAction *dirAutoLandmarksAct;
	QAction *dirCentroidMeasureAct;
	QAction *dirGenerateDataAct;


	// Action registration
	QAction *pcaiAct;

	// private methods
	void createActions();
	void createMenus();
	void createToolBars();
	void createStatusBar();
	void createFileMenu();
	void createViewMenu();
	void createHelpMenu();
	void createSegmentationMenu();
	void createLandmarksMenu();
	void createRegistrationMenu();

	void activeFunction();
	void viewMenuUpdateActions();
	void scaleImage(double factor);
	void adjustScrollBar(QScrollBar *scrollBar, double factor);

	void displayLandmarks(Image *image, std::vector<Point> lms, RGB color);
};

#endif /* IMAGEVIEWER_H_ */
