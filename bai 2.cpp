// số blum n là tích của 2 số nguyên tố có dạng 3(mod4)

// Bước 1: Tạo mảng số blum nhỏ hơn N 
//     liệt kê các số dạng 3x+4 nhỏ hơn N.
//     tạo mảng số blum nhỏ hơn N từ tích 2 số trên
// Bước 2: Tìm cặp số blum có tổng là số blum
//     tính tổng các số trong mảng blum
//    kiểm tra tổng có tồn tại trong mảng blum không
//Bước 3: Kiểm tra 2 số M có tồn tại trong dãy blum đc tạo không
//    kiểm tra M với mảng blum trên

//cai dat

#include <iostream>
#include <vector>
using namespace std;

//ktra snt dang 3(mod 4)
bool snt(int n){
    return n%4==3;
}
//tao mang so blum
vector<int> blum(int N){
    vector<int> songuyento;
    vector<int> soBlum;
    for(int i=1;i<N;i++){           //add so dang 3(mod4) vao snt
        if (snt(i)) songuyento.push_back(i);   
    }
    for(int i=0;i<songuyento.size();i++){       
        for(int j=0;j<songuyento.size();j++){
            if((songuyento[i]*songuyento[j]<N))     //tao mang so blum tu tich 2 snt
                soBlum.push_back(songuyento[i]*songuyento[j]);
        }
    }
    return soBlum;
}

void pairs(vector<int>& soBlum, int N){
    for(int i=0;i<soBlum.size();i++){
        for(int j=0;j<soBlum.size();j++){
            int tong= soBlum[i]+soBlum[j];
            //ktra tong co ton tai khong
            bool ktrablum =0 ;
            for(int k=0;k<soBlum.size();k++){
                if(soBlum[k]==tong) {
                    ktrablum=1;     break;}
            }
            if(tong<N && ktrablum==1){  //in ra cac cap hop le
                cout<< "(" << soBlum[i] <<","<<soBlum[j]<<")"<<endl;
            }
        }
    }
}
//ktra M co ton tai trong day khong
bool checkM(vector<int>& soBlum, int M){
    for(int i=0;i<soBlum.size();i++){
        if(soBlum[i]==M)    return 1;
    }
    return 0;
}