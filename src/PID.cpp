#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p, double i, double d, double cte_prev) {
    Kp = p;
    Ki = i;
    Kd = d;
    cte_pre = cte_prev;
    cte_tot = 0;
}

void PID::UpdateError(double cte) {
    cte_tot += cte;
    p_error = Kp * cte;
    i_error = Ki * cte_tot;
    d_error = Kd * (cte - cte_pre);
    cte_pre = cte;


}

double PID::TotalError() {
    return -(p_error + i_error + d_error);
}
