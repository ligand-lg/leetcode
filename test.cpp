#include "leetcode.h"

double f(double w0, double w1) {
  return log(1 + exp(w0 + 2 * w1)) + log(1 + exp(-1 * w0 - 7 * w1)) +
         log(1 + exp(-1 * w0 - 4 * w1)) + log(1 + exp(w0 + w1)) +
         log(1 + exp(-1 * w0 - 5 * w1) + log(1 + exp(w0 + 4.5 * w1)));
}

vector<double> minValueF2() {
  double minV = DBL_MAX;
  double minW0, minW1;
  for (double w0 = -10; w0 <= -3; w0 += 0.001) {
    double _minV = DBL_MAX;
    double _minW1;
    for (double w1 = -5; w1 <= 5; w1 += 0.001) {
      double v = f(w0, w1);
      if (v < _minV) {
        _minV = v;
        _minW1 = w1;
      }
      if (v < minV) {
        minV = v;
        minW0 = w0;
        minW1 = w1;
      }
    }
    cout << "w0=" << w0 << " w1=" << _minW1 << " f=" << _minV << endl;
  }
  return vector<double>{minW0, minW1};
}

vector<double> minValueF() {
  double minV = DBL_MAX;
  double minW0, minW1;
  for (double w0 = -20; w0 <= 10; w0 += 1) {
    double w1Left = -20;
    double w1Right = 20;

    double w1Mid, midV;
    double alpha = 0.5;

    while (w1Left <= w1Right) {
      w1Mid = ((w1Right - w1Left) / 2) + w1Left;
      midV = f(w0, w1Mid);

      double midLeftV = f(w0, w1Mid - alpha);
      double midRightV = f(w0, w1Mid + alpha);

      if (midV > midLeftV) {
        w1Right = w1Mid - alpha;
      } else if (midV > midRightV) {
        w1Left = w1Mid + alpha;
      } else {
        break;
      }
    }

    cout << "w0=" << w0 << " w1=" << w1Mid << " f=" << midV << endl;
    if (midV < minV) {
      minW0 = w0;
      minW1 = w1Mid;
      minV = midV;
    }
  }

  return vector<double>{minW0, minW1};
}

int main(int, char **) {
  //  minValueF();
  minValueF2();
}
