#include<iostream>
using namespace std;int main(){
    int L=2, A=0, G=0, E=1;
    for(;L<10;L++){
        for(A=0;A<10;A++){
            if(L==A||A==E) {A++;}
            for(G=0;G<10;G++){
                if(A==G||G==E||G==L) G++;
                if((L*1000+A*100+G*10+E)/L==E*1000+G*100+A*10+L){
                    cout<<"EGAL="<<E<<G<<A<<L<<endl;
                }
            }
        }
    }
    //system("pause");
    return 0;
}
