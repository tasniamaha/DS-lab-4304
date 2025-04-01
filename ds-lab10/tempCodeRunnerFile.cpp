for(size_t i=1;i<comp.size();i++){
        newroad.emplace_back(comp[i-1],comp[i]+1);
    }