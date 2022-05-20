#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
//You can use that just for documents like *.txt files.




bool Encrypt(const char* path, const char* exportPath){

    std::vector<std::string> strings;

    std::fstream file;
    file.open(path, std::ios::in);
    std::string word;
    while(std::getline(file,word)){
        strings.push_back(word);
    }

    for(auto& b : strings){
        for(int i = 0; i < b.size(); i++){
            b[i] = (short)b[i]+2;
        }
    }
    file.close();
    
    FILE *f = fopen(exportPath,"w");
    for(auto &b : strings){
        fwrite(&b[0],b.size(),1,f);
        fwrite("\n",1,1,f);
    }
    fclose(f);
    return true;
}

bool DeEncrypt(const char* path){

    std::vector<std::string> strings;

    std::fstream file;
    file.open(path, std::ios::in);
    std::string word;
    while(std::getline(file,word)){
        strings.push_back(word);
    }

    for(auto& b : strings){
        for(int i = 0; i < b.size(); i++){
            b[i] = (short)b[i]-2;
        }
    }
    file.close();
    
    FILE *f = fopen(path,"w");
    for(auto &b : strings){
        fwrite(&b[0],b.size(),1,f);
        fwrite("\n",1,1,f);
    }
    fclose(f);

    return true;
}


int main(int argc, char** argv){

    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "--encrypt") == 0){
            Encrypt(argv[i+1],argv[i+2]);   
            printf("Successfully encrypted file %s\n", argv[i+1]);
        }
        if(strcmp(argv[i],"--deencrypt") == 0){
            DeEncrypt(argv[i+1]);
            printf("Successfully deencrypted file %s\n", argv[i+1]);
        }
    }

    return EXIT_SUCCESS;
}
