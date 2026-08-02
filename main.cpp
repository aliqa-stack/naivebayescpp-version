#include <iostream>
#include <sstream>
#include <vector>
#include <map>

class NaiveBayes{
    public:
    std::map<std::string, int> countOf_data;
    std::map<std::string, int> vocabUnik;
    int total_data = 0;
   // std::map<std::string, int> countOf_data2;

};

class DataSet : public NaiveBayes{
    public:
    std::string data1;
    std::string data2;
      
    std::string tokinisasi(std::string& data){
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        for(auto& t : tokens){
            std::cout<<t<<"\n";
            countOf_data[t]++;
            vocabUnik[t]++;
            if(vocabUnik[t]==1 && vocabUnik.size() > 4){
                continue;
            }
            std::cout<<"kata yang keluar:"<<vocabUnik[t]<<"\n";

            
            total_data++;
            //std::cout<<"jumlah kata yang keluar:"<<countOf_data[t]<<"/"<<total_data<<"\n";
        }
        return tokens[0];
    }

    std::string OutputData(std::string& data1){
        std::cout<< "Data 1: " << data1 << std::endl;
        return data1;
    }

};

int main(){
    DataSet data;
    data.data1 = "Yang saya hormati Menteri Perumahan dan Kawasan Permukiman Saudara Maruarar Sirait, beserta seluruh jajaran Kementerian Perumahan dan Kawasan Permukiman yang hadir;.....\n"
    "Ketua Dewan Perwakilan Daerah Republik Indonesia Saudara Sultan Bachtiar Najamudin. Para Menteri Koordinator, para Menteri, Jaksa Agung, Panglima TNI. Saya ulangi, ya, Jaksa Agung, Kapolri. Selalu berdekatan, baru Panglima TNI....,pidatoP"
    "Kepala Badan dan para Wakil Menteri, serta seluruh anggota Kabinet Merah Putih yang hadir, yang daftarnya terlampir. Di sini ada 40 nama, tapi sebagian sudah disebut tadi. Perlu disebut lagi? Enggak apa-apa ya, tidak mengurangi rasa hormat ya, pidatoP"
    "Tapi ada, di sini ada, apa, yang saya sebut, saya kira tadi. Menteri Perumahan, salah tadi bukan, ini, apa, Ibu Destry sekarang adalah pejabat, Pejabat Gubernur Sementara, PGS, ya, singkatannya, Pejabat Gubernur Sementara. Jadi pejabat. Kayaknya, gimana? Oke. Terserah DPR nanti, ya, kira-kira, pidatoP"
    "Jadi saya tidak sebut, ya, Menteri-menteri. Ini Menteri-menteri ini jago-jago semua ini, Menteri-Menteri saya, Menko-Menko saya semua, ya. Kepala Badan, Wakil Menterinya juga jagoan semua, ya. Tadi Menteri UMKM juga kumisnya gagah sekali, kok, itu, dari Kerala keturunannya. Dia senang, Perdana Menteri Modi datang dia senang sekali itu. Saya kira kau keturunan Gujarat, ternyata bukan. Kerala, Kerala, pidatoP";
    data.data2 = "data ini berbeda dengan data1 untuk menguji algoritma naive bayes, nanti nya data ini akan diubah, pidato";

    data.tokinisasi(data.data1);
    //data.tokinisasi(data.data1);
    





}