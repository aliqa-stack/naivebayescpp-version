#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

class NaiveBayes{
    public:
    std::map<std::string, int> countOf_Pspeech;
    std::map<std::string, int> countOf_Hspeech;
    std::map<std::string, bool> vocabUnik;
    int total_Pspeech = 0;
    int total_Hspeech = 0;
    int totalPword = 0;
    int totalHword = 0;
    // std::map<std::string, int> countOf_data2;

};

class DataSet : public NaiveBayes{
    public:
    std::string data1;
    std::string data2;
    
    std::string tokinisasiData1(std::string& data){
        int vocabUnikSize = vocabUnik.size();
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        for(auto& t : tokens){
            std::cout<<t<<"\n";
            countOf_Pspeech[t]++;
            vocabUnik[t] = true;
         
           // std::cout<<"kata yang keluar:"<<vocabUnik[t]<<"\n";

            
            total_Pspeech++;
            totalPword++;
            std::cout<<"jumlah kata yang keluar:"<<countOf_Pspeech[t]<<"/"<<total_Pspeech<<"\n";
        }
        return tokens[0];
    }

    std::string tokinisasiData2(std::string& data){
        int vocabUnikSize = vocabUnik.size();
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        for(auto& t : tokens){
            std::cout<<t<<"\n";
            countOf_Hspeech[t]++;
            vocabUnik[t] = true;
           
           std::cout<<"kata yang keluar:"<<vocabUnikSize<<"\n";
           
           
           total_Hspeech++;
           totalHword++;
            std::cout<<"jumlah kata yang keluar:"<<countOf_Hspeech[t]<<"/"<<total_Hspeech<<"\n";
        }
        return tokens[0];

    }

    std::string probability(std::string& data){
        float naiveClass = total_Pspeech + total_Hspeech;
        float Pspeech = std::log((float)(total_Pspeech + 1) / (float)(naiveClass + 1));
        float Hspeech = std::log((float)(total_Hspeech + 1) / (float)(naiveClass + 1));
        
        float Logp = Pspeech;
        float Logh = Hspeech;
        
        std::vector<std::string> words = {tokinisasiData1(data)};
        
        int vocabUnikSize = vocabUnik.size();
        for(auto& v : words){
            int priorx = countOf_Pspeech[v] ? countOf_Pspeech[v] : 0;
            int priory = countOf_Hspeech[v] ? countOf_Hspeech[v] : 0;
       
              float likehoodP = std::log((float)(priorx + 1)/ (float)(totalPword + vocabUnikSize + 1));
              float likehoodH = std::log((float)(priory + 1)/ (float)(totalHword + vocabUnikSize + 1));

              Logh += likehoodH;
              Logp += likehoodP;

              std::cout<<"Logp: "<<Logp<<"\n";
              std::cout<<"Logh: "<<Logh<<"\n";

              
        }

        return Logp > Logh ? "politic speech" : "non politic speech";
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

   // data.tokinisasiData1(data.data1);
    data.probability(data.data1);
    //data.tokinisasiData2(data.data2);
    





}