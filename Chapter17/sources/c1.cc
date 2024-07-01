#include <iostream>
#include <fstream>//for working with files
#include <cstdlib>
#include <cstring>

int main(int argc, char **argv)
{
   using namespace std;
   // // ofstream obj;
   // // obj.open("../makarella.txt");
   // ofstream o("mostpost.txt");
   // o << "Something";

   //program: ask for a name, create a file with that name, store information in that file,end
   // cout << "Enter your name: ";
   // char name[30];//temp buff
   // while(!cin.get(name, 30))//if an empty line occurs, this is false, since failbit is set
   // {
   //    cin.clear();//reset the failed bits
   //    while(cin.get() != '\n')
   //       continue;
   //    cout << "\nPlease enter a valid value!!!";//repeat until the correct value is set
   // }
   // ofstream out(name);
   // out << name;
   // out.close();//close the stream


   // cout << endl << "Here are the contents of the file that you created: ";
   // ifstream in(name);
   // char t[30];
   // in.getline(t, 30);
   // cout << t;
   // in.close();


   //program: searches for the files entered through command line, counts the number of letters:
   // if(argc == 1)
   // {
   //    cerr << "Insufficient amount of args. Terminating." << endl;
   //    exit(EXIT_FAILURE);
   // }
   // ifstream ref;
   // size_t total_letters = 0;
   // for(int i = 1; i < argc; ++i)
   // {
   //    ref.open(argv[i]);//open the file
   //    if(!ref.is_open())
   //    {
   //       cerr << "Unable to open the file " << argv[i] << endl;
   //       continue;
   //    }
   //    char buff[100];//read by 100 chars
   //    while(ref.getline(buff, 100))
   //    {
   //       total_letters += strlen(buff);
   //       if(!ref)//if something bad happened to ref
   //          ref.clear();//reset the fail bits
         
   //    }
   //    total_letters += strlen(buff);//add the chars for the last time:
   //    ref.clear();
   //    ref.close();//close the stream
   // }
   // cout << "The total number of letters in specified files: " << total_letters;



   //check whether the file exists, read the contents, append to the file, exit:
   // const char *na = "Exumple";
   // ifstream in;
   // cout << "Getting contents from the file: " << endl;
   // in.open(na);
   // if(!in.is_open())
   // {
   //    cout << "The file can't be opened for reading." << endl;

   // }
   // else
   // {
   //    cout << "The file CAN be read: " << endl;
   // }
   // char buff[100];//read from the file:
   // while(in.getline(buff, 100))
   // {
   //    cout << buff;
   // }
   // cout << buff;
   // in.clear();
   // in.close();
   // cout << "Would you like to write to a file?";
   // char c;
   // cin.get(c);
   // cin.get();
   // if(!(c == 'y' || c == 'Y'))
   //    exit(EXIT_SUCCESS);
   // ofstream out;
   // out.open(na, ios_base::out | ios_base::app);
   // if(!out.is_open())
   // {
   //    cout << "\nCan not open the file for writing data.";
   //    abort();
   // }
   // cout << "\nEnter the data: ";
   // while(cin.get(buff, 100, '\n'))
   // {
   //    out.write(buff, strlen(buff));
   // }
   // cout << "Displaying the contents of the file: " << endl;
   // ifstream in_2("Example");
   // char ch;
   // while(in_2.get(ch))
   //    cout.put(ch);
   // in_2.clear();
   // in_2.close();

   //reading and writing data in binary mode:
   ofstream fout("binary", std::ios_base::out | std::ios_base::app | std::ios_base::binary);
   cout << "Writing to a binary file" << endl;
   struct ex{char arr[40]; int value; float something;};
   ex ex1 = {"Jolly", 14, 123.3F};
   fout.write((char *)&ex1, sizeof(ex));
   fout.clear();
   fout.close();
   cout << "Retrieving data in binary mode: " << endl;
   ifstream fin("binary", std::ios_base::in | std::ios_base::binary);
   cout << "The contents: " << endl;
   ex temp;
   while(fin.read((char*)&temp, sizeof(ex)))
   {
      cout << "Name: " ;
      cout.width(20); cout << temp.arr;
      cout << ", value: " << temp.value << ", something: " << temp.something;
   }
   return 0;
}