#include <iostream>
#include <point_set/point.h>
#include <point_set/on-disk-point-set-list.h>

using namespace libpmk;
using namespace std;


int main()
{


    PointSetList *	pointSetList=new OnDiskPointSetList("~/Scrivania/PORKMI/libpmk-2.5/libpmk2/pyramids/testdata/testpointsets.psl");
	cout << pointSetList;

    Point punto(14);

    cout << "Hello world!" << endl;
    return 0;
}
