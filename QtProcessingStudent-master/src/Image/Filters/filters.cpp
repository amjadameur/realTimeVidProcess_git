#include "filters.h"

Filters::Filters(vector<int> &vect) : chosenFilters(vect) {
    buffOutptr = NULL;

    filters.push_back(new RedChannel());
    filters.push_back(new GreenChannel());
    filters.push_back(new BlueChannel());
    filters.push_back(new GreyChannel());
    filters.push_back(new ReliableGreyChannel());

    filters.push_back(new DownSample());
    filters.push_back(new LinearDownSample());
    filters.push_back(new CubicDownSample());

    filters.push_back(new UpSample());
    filters.push_back(new LinearUpSample());
    filters.push_back(new CubicUpSample());

    filters.push_back(new Blur());
    blurPtr = filters[filters.size()-1]; // utile pour l'affecter au filtre C3 après

    filters.push_back(new AutoAdapt());
    filters.push_back(new Inverse());

    filters.push_back(new B0());
    filters.push_back(new B1());
    filters.push_back(new B2());
    filters.push_back(new B3());
    filters.push_back(new M0());
    filters.push_back(new M1());
    filters.push_back(new M2());
    filters.push_back(new M3());
    filters.push_back(new M4());
    filters.push_back(new M5());
    filters.push_back(new M6());
    filters.push_back(new M7());
    filters.push_back(new M8());
    filters.push_back(new M9());

    filters.push_back(new C1());
    filters.push_back(new C2());
    filters.push_back(new C3((Blur*)  blurPtr));
    filters.push_back(new C4());

    nbFilters = filters.size();
}

Filters::~Filters() {
    for(unsigned int i = 0; i < filters.size(); i++) {
        delete filters[i];
        filters.pop_back();
    }
}

void Filters::refreshPrevBuffers(FastImage *bufferIn) {
    ((Blur*) blurPtr)->refreshPrevIm(bufferIn);
}

bool Filters::allFiltersOff() {
    // vérifie si les filtres séléctionnés par l'utilisateur sont tous désactivés
    for(unsigned int i = 0; i < chosenFilters.size(); i ++) {
        if(chosenFilters[i] >= 0) {
            return false;
        }
    }
    return true;
}

void Filters::filter(FastImage *bufferIn, FastImage *bufferOut) {
    refreshPrevBuffers(bufferIn);

    if(!chosenFilters.size() || allFiltersOff()){
         bufferOut->FastImageCpy(bufferIn);

    } else {
         int fitlerIdx;
         buffOutptr = bufferIn;

         for(unsigned int i = 0; i<chosenFilters.size(); i++) {
             fitlerIdx = chosenFilters[i];
             if(fitlerIdx >= 0) {
                filters[fitlerIdx]->filter(buffOutptr, bufferOut);
                buffOutptr = bufferOut;
             }
         }
         buffOutptr = NULL;
    }
}


