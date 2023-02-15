/** void showTheFile(ifstream &inputFile){
     string oneLine;
    while(inputFile.good()){
        if(inputFile.peek() == '#'){
            cout << "here comes a comment" << endl;

        }

        if(inputFile.eof()) return;
        getLine(inputFile, oneLine);

    }
}




void skipAnyCommentLines(ifstream &infile){
    string textLine;
    char ch = infile.peek();
    while(ch == '#' || ch == '\n'){ // its not data line
        getline(infile,textLine); //throw it away
        ch = infile.peek(); //peek at next line
    }
}
*/


