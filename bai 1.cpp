#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int tg = a; a=b; b=tg;
}
//ham sap xep
void sort(int mau[],int n){ //mang khong can tham chieu
    int i=0, k=n-1;    //i de duyet tu dau, k duyet tu cuoi
    for(int j=0;j<=k;){
        if(mau[j]==0) {swap(mau[j],mau[i++]); j++;}
        else if(mau[j]==2) {swap(mau[j],mau[k--]);} //khong tang j de ktra ptu moi tai j
        else j++;
    }
}

int main(){
    int n;
    cout<<"nhap n: ";    cin>>n;
    string color[n];  //chuoi mau
    cout<<"nhap vao cac mau do trang xanh tuy y:"<<endl;
    for(int i=0;i<n;i++){
        cin>>color[i];
    }
    //ma hoa mau
    int mau[n];
    for(int i=0;i<n;i++){
        if (color[i]=="do") mau[i]=0;
        else if (color[i]=="trang") mau[i]=1;
        else mau[i]=2;
    }

    sort(mau,n);

    //output
    cout<<"sau khi sap xep: "<<endl;
    for(int i=0;i<n;i++){
        if(mau[i]==0) cout<<"do ";
        else if(mau[i]==1) cout<<"trang ";
        else cout<<"xanh ";
    }
    return 0;
}