cout<<"Adjacency list:\n";
        for(int i=0;i<V;i++){
            cout<<i+1<<": ";
            for(int neighbour:adjlist[i]){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }