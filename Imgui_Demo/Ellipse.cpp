#include "Ellipse.h"

Ellipse::Ellipse(double aConstr, double bConstr, int numberPointsConstr, double offSetXConstr,
                 double offSetYConstr, double angleConstr) {

    //Error catcher. a<b for ellipses, so this will just swap them if they are.
    if (aConstr < bConstr) {
        a = bConstr;
        b = aConstr;
    } else {
        a = aConstr;
        b = bConstr;
    }
    numberPoints = numberPointsConstr + 1; //Needs one more to work properly (to finish the circle
    ellipsePoints.reserve(numberPoints); //Not needed? Done anyway
    offsetX = offSetXConstr;
    offsetY = offSetYConstr;
    angle = angleConstr * (double) (std::numbers::pi / 180);
    NewList();

}

/**
 * Updates the number of points the ellipse has
 * @param newNumberPoints
 */
void Ellipse::UpdateNumberPoints(int newNumberPoints) {
    numberPoints = newNumberPoints;
    NewList();
}

/**
 * Creates a list  of points containing all points of the ellipse.
 * Defines a bunch of constants before starting the loop where it finds all the points
 */
void Ellipse::NewList() {

    double piMultiply = (double) (std::numbers::pi / 180);
    double e = double(sqrt(1 - (b * b) / (a * a)));
    double rTop = double(a * (1 - e * e));
    //The angle it needs to change by to reach 360 after using all the points. -1 so it reaches all the way around
    double angleChange = (double) (360.0f / (numberPoints -
                                             1));

    double xMax = (double) (a * (1 + e));
    double xMin = (double) (a * (1 - e));
    double correctionFactor = (xMax - xMin) / 2;

    double angleChangeSin = sin(angle);
    double angleChangeCos = cos(angle);

    for (int i = 0; i <= numberPoints; i++) {
        //check if these (and the above ones) double casts are needed. Not sure.
        double theta = (double) (i * angleChange * piMultiply);
        double r = (double) (rTop / (1 - e * cos(theta)));
        double x = r * cos(theta) - correctionFactor + offsetX;
        double y = r * sin(theta) + offsetY;
        EllipsePoint newPoint;
        newPoint.x = x * angleChangeCos - y * angleChangeSin;
        newPoint.y = y * angleChangeCos + x * angleChangeSin;
        ellipsePoints.push_back(newPoint);
    }
}

/**
 * @return an array containing all the x points.
 */
double *Ellipse::GetXArray() {
    double *returnArray = new double[numberPoints];
    for (int i = 0; i < numberPoints; i++) {
        returnArray[i] = ellipsePoints[i].x;
    }
    return returnArray;
}

/**
 * @return an array containing all the y points.
 */
double *Ellipse::GetYArray() {
    double *returnArray = new double[numberPoints];
    for (int i = 0; i < numberPoints; i++) {
        returnArray[i] = ellipsePoints[i].y;
    }
    return returnArray;
}

/**
 *
 * @return the number of points that the ellipse has
 */
int Ellipse::GetNumberPoints() {
    return numberPoints;
}

