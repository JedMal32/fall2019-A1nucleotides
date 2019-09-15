#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using std::string;

int main(int argc, char** argv){
  bool keepGoing = true;
  bool useNewFile = false;
  string file = argv[1];

  while(keepGoing){
    //variables
    int sum = 0;
    int sumDouble = 0;
    int sumSquared = 0;
    int lines = 0;
    //incremental counters
    int a = 0;
    int c = 0;
    int t = 0;
    int g = 0;
    int aa = 0;
    int ac = 0;
    int at = 0;
    int ag = 0;
    int ca = 0;
    int cc = 0;
    int ct = 0;
    int cg = 0;
    int ta = 0;
    int tc = 0;
    int tt = 0;
    int tg = 0;
    int ga = 0;
    int gc = 0;
    int gt = 0;
    int gg = 0;

    std::ifstream input(file);
    for(string line; getline(input, line);){

      ++lines;
      sumSquared += line.length()*line.length();

      //'Segmentation fault' protection
      if(line.length() == 0){
        break;
      }

      //for loop to count individual nucleotides
      for(int i = 0; i < line.length() ; ++i){
        ++sum;
        char currentChar = tolower(line[i]);
        if(currentChar == 'a'){
          a++;
        }else if(currentChar == 'c'){
          c++;
        }else if(currentChar == 't'){
          t++;
        }else if(currentChar == 'g'){
          g++;
        }
      }

      //for loop to count biagrams of nucleotides
      for(int i = 0; i < line.length()-1 ; ++i){
        ++sumDouble;
        string currentStr(1, tolower(line[i]));
        currentStr.append(1, tolower(line[i+1]));
        if(currentStr == "aa"){
          aa++;
        }else if(currentStr == "ac"){
          ac++;
        }else if(currentStr == "at"){
          at++;
        }else if(currentStr == "ag"){
          ag++;
        }else if(currentStr == "ca"){
          ca++;
        }else if(currentStr == "cc"){
          cc++;
        }else if(currentStr == "ct"){
          ct++;
        }else if(currentStr == "cg"){
          cg++;
        }else if(currentStr == "ta"){
          ta++;
        }else if(currentStr == "tc"){
          tc++;
        }else if(currentStr == "tt"){
          tt++;
        }else if(currentStr == "tg"){
          tg++;
        }else if(currentStr == "ga"){
          ga++;
        }else if(currentStr == "gc"){
          gc++;
        }else if(currentStr == "gt"){
          gt++;
        }else if(currentStr == "gg"){
          gg++;
        }

      }

    }

    //calculates all probabilties and statistics
    float mean = float(sum)/lines;
    float variance = sumSquared/lines-mean*mean;
    float stdDeviation = sqrt(variance);
    float probA = float(a) / sum;
    float probC = float(c) / sum;
    float probT = float(t) / sum;
    float probG = float(g) / sum;
    float probAA = float(aa) / sumDouble;
    float probAC = float(ac) / sumDouble;
    float probAT = float(at) / sumDouble;
    float probAG = float(ag) / sumDouble;
    float probCA = float(ca) / sumDouble;
    float probCC = float(cc) / sumDouble;
    float probCT = float(ct) / sumDouble;
    float probCG = float(cg) / sumDouble;
    float probTA = float(ta) / sumDouble;
    float probTC = float(tc) / sumDouble;
    float probTT = float(tt) / sumDouble;
    float probTG = float(tg) / sumDouble;
    float probGA = float(ga) / sumDouble;
    float probGC = float(gc) / sumDouble;
    float probGT = float(gt) / sumDouble;
    float probGG = float(gg) / sumDouble;

    //prints header to text file
    std::ofstream output;
    output.open("Malashock.out");
    output << "Jed Malashock\n2298758\nSection 2\n";
    output << "\nSum: " << sum << "\nMean: " << mean << "\nVariance: " << variance << "\nStandard Deviation: " << stdDeviation;
    output << "\nProbability of A: " << probA << "\nProbability of C: " << probC << "\nProbability of T: " << probT << "\nProbability of G: " << probG;
    output << "\nProbability of AA: " << probAA << "\nProbability of AC: " << probAC << "\nProbability of AT: " << probAT << "\nProbability of AG: " << probAG;
    output << "\nProbability of CA: " << probCA << "\nProbability of CC: " << probCC << "\nProbability of CT: " << probCT << "\nProbability of CG: " << probCG;
    output << "\nProbability of TA: " << probTA << "\nProbability of TC: " << probTC << "\nProbability of TT: " << probTT << "\nProbability of TG: " << probTG;
    output << "\nProbability of GA: " << probGA << "\nProbability of GC: " << probGC << "\nProbability of GT: " << probGT << "\nProbability of GG: " << probGG;
    output << "\n";

    //loop to generate and print 1000 lines of nucleotides
    srand(time(NULL));
    for(int i=0; i<1000; ++i){
      //gives random length based upon guassian distribution
      float r1 = float(rand() % 1000)/1000;
      float r2 = float(rand() % 1000)/1000;
      float rC = sqrt(-2*log(r1)) * cos(2*3.141592*r2);
      int randStrLength = stdDeviation*rC+mean;

      //string creator and filler
      string createdString = "";
      for(int i = randStrLength; i > 0; i = i-2){ //I took some creative control (without any math proof) and based my random probabilties based upon the 4 nucleotides and not the 16 pair types
        float selector = float(rand() % 10000)/10000;

        if(i == 1){
          if(selector < probA){
            createdString.append("A");
          }else if(selector < probA+probC){
            createdString.append("C");
          }else if(selector < probA+probC+probT){
            createdString.append("T");
          }else{
            createdString.append("G");
          }
        }else{
          if(selector < probAA){
            createdString.append("AA");
          }else if(selector < probAA+probAC){
            createdString.append("AC");
          }else if(selector < probAA+probAC+probAT){
            createdString.append("AT");
          }else if(selector < probAA+probAC+probAT+probAG){
            createdString.append("AG");
          }else if(selector < probAA+probAC+probAT+probAG+probCA){
            createdString.append("CA");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC){
            createdString.append("CC");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT){
            createdString.append("CT");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG){
            createdString.append("CG");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA){
            createdString.append("TA");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA+probTC){
            createdString.append("TC");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA+probTC+probTT){
            createdString.append("TT");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA+probTC+probTT+probTG){
            createdString.append("TG");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA+probTC+probTT+probTG+probGA){
            createdString.append("GA");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA+probTC+probTT+probTG+probGA+probGC){
            createdString.append("GC");
          }else if(selector < probAA+probAC+probAT+probAG+probCA+probCC+probCT+probCG+probTA+probTC+probTT+probTG+probGA+probGC+probGT){
            createdString.append("GT");
          }else{
            createdString.append("GG");
          }

        }

      }

      //string printer
      output << "\n";
      output << createdString;

    }

    //asks to evaluate another file
    string repeat;
    std::cout << "Would you like to process another list? (y/n)";
    std::cin >> repeat;
    if(repeat == "y"){
      std::cout << "What is the name of the file you would like to evaluate? (___.txt)";
      std::cin >> file;
      useNewFile = true;
    }else if(repeat == "n"){
      keepGoing == false;
      break;
    }
  }

}
