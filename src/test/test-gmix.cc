#include <cstdio>
#include <vector>
#include "gmix.h"
#include "image.h"
#include "MtRng.h"

using namespace std;

using gmix::GMix;
using gmix::Gauss;


int main(int argc, char **argv)
{

    Gauss gempty;
    gempty.print();

    Gauss ginit(1.0, 25.0, 26.0, 4.0, 1.6, 3.7);
    ginit.print();

    Gauss gset;
    gset.set(200.0, 15.2, 14.75, 1.8, 0.25, 1.9);
    gset.print();

    vector<double> pars;

    pars.push_back(0.4);
    pars.push_back(16.0);
    pars.push_back(15.0);
    pars.push_back(8.0);
    pars.push_back(1.5);
    pars.push_back(5.0);

    pars.push_back(0.6);
    pars.push_back(8.0);
    pars.push_back(15.0);
    pars.push_back(4.0);
    pars.push_back(2.2);
    pars.push_back(7.0);

    GMix obj_gmix(pars);

    printf("\n");
    obj_gmix.print();


    double row=16.0, col=15.0;
    printf("eval(%g,%g) = %g\n", row, col, obj_gmix(row,col));

    pars[1] = 18.0;
    pars[2] = 18.1;
    obj_gmix.set_from_pars(pars);

    obj_gmix.print();

    printf("eval(%g,%g) = %g\n", row, col, obj_gmix(row,col));

    long nrows=32, ncols=32;
    image::Image im(nrows, ncols);

    obj_gmix.render(im);
    im.show("/tmp/timage-32432.dat");

    MtRng::MtRng64 rng;
    rng.init_dev_urandom();

    im.add_gaussian_noise(rng, 0.001);
    im.show("/tmp/timage-32432.dat");


    return 0;
}