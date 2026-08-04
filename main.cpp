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
    

    //tahap tokenisasi dari data 
    std::vector<std::string> tokinisasiData1(std::string& data){
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
            vocabUnik[token] = true;
        }
      
        return tokens;
    }


    //bedakan dari label data 
    void train(std::string& data, std::string label){
        std::vector<std::string> words = tokinisasiData1(data);
        if(label == "politic speech"){
            total_Pspeech++;
            for(auto& w : words){
                totalPword++;
                countOf_Pspeech[w]++;
            }
        }else if(label == "non politic speech"){
            total_Hspeech++;
            for(auto& w : words){
                totalHword++;
                countOf_Hspeech[w]++;
            }
        }
    }

  //  std::string tokinisasiData2(std::string& data){
        //int vocabUnikSize = vocabUnik.size();
        //std::stringstream ss(data);
        //std::string token;
        //std::vector<std::string> tokens;
        //while(getline(ss, token, ' ')){
            //tokens.push_back(token);
        //}
        //for(auto& t : tokens){
            //std::cout<<t<<"\n";
            //countOf_Hspeech[t]++;
            //vocabUnik[t] = true;
           
           //std::cout<<"kata yang keluar:"<<vocabUnikSize<<"\n";
           
           
           //total_Hspeech++;
           //totalHword++;
            //std::cout<<"jumlah kata yang keluar:"<<countOf_Hspeech[t]<<"/"<<total_Hspeech<<"\n";
        //}
        //return tokens[0];

    //}
    
    //rumus menghitung teorema bayes untuk data yang ada
    std::string probability(std::string& data){
        //kumpulkan semua data yang ada menjadi 1
        float naiveClass = total_Pspeech + total_Hspeech;
        //bagi data1 dengan keseluruhan data yang ada untuk menghitung probabilitas
        //laplace smoothing untuk menghindari pembagian dengan 0 tambahkan 1 ke total_pspeech
        float Pspeech = std::log((float)(total_Pspeech + 1) / (float)(naiveClass + 1));
        float Hspeech = std::log((float)(total_Hspeech + 1) / (float)(naiveClass + 1));
        
        float Logp = Pspeech;
        float Logh = Hspeech;
        
        std::vector<std::string> words = tokinisasiData1(data);
        
        int vocabUnikSize = vocabUnik.size();
        for(auto& v : words){
            int priorx = countOf_Pspeech.count(v) ? countOf_Pspeech[v] : 0;
            int priory = countOf_Hspeech.count(v) ? countOf_Hspeech[v] : 0;
       
            //hitung likeood data 1 dan data2 
              float likehoodP = std::log((float)(priorx + 1)/ (float)(totalPword + vocabUnikSize + 1));
              float likehoodH = std::log((float)(priory + 1)/ (float)(totalHword + vocabUnikSize + 1));

              Logh += likehoodH;
              Logp += likehoodP;

              std::cout<<"Logp: "<<Logp<<"\n";
              std::cout<<"Logh: "<<Logh<<"\n";
              std::cout<<"vocabulary: "<<vocabUnikSize<<"\n";

              
        }
        for(auto& v : countOf_Hspeech){
            std::cout<<"vocabulary: "<<v.first<<"\n";
        }
        
        //hitung apakah data1 lebih besar dari data2, maka klasifikasikan sebagai "pspeech"
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
    data.data2 = "data ini berbeda dengan data1 untuk menguji algoritma naive bayes, nanti nya data ini akan diubah, pidato"
    "Bapak dan Ibu tamu undangan, serta para hadirin yang saya hormati, marilah kita panjatkan puji syukur atas kehadirat Allah SWT atas limpahan rahmat-Nya kepada kita semua.";

   // data.tokinisasiData1(data.data1);
   data.train(data.data1, "politic speech");
   data.train(data.data2, "non politic speech");
    //data.tokinisasiData2(data.data2);

    std::vector<std::string> testData = {
        "warahmatullahi wabarakatuh, bapak ibu yang terhormat dan teman teman yang ada disini, saya sekarang akan menyampaikan pidato"
    };

        for(auto& test : testData){
            std::string result = data.probability(test);
            std::cout << "Hasil Klasifikasi: " << result << std::endl;
        }

    return 0;
}