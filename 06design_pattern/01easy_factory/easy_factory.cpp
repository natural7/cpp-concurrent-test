#include "easy_factory.h"


// easy_factory::easy_factory()
// {
//     cout << "easy_factory constructor"<<endl;
// }

shared_ptr<car> easy_factory::create_car(CAR car_type)
{
    car *pcar = NULL;
    switch (car_type)
    {
        case CAR_BWM:
            pcar = new BMW();
        break;

        case CAR_Audi:
            pcar = new Audi();
        break;
        default:
            cout << "invalid type"<<endl;
    }
    shared_ptr<car> pscar(pcar);
    return pscar;
}