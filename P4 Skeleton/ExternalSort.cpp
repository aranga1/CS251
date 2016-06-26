#include "ExternalSort.h"


/*
	External Sorting algorithm.
	Step 1: Reads the input file one chunk at a time
	Step 2: Sorts each chunk
	Step 3: Writes each chunk to a temporary file
	Step 4: Performs a k-wise merge on the temporary files

*/
void extern_sort(string in_fname, string out_fname,
		string chunk_location, int chunk_size)
{
    ifstream inputStream;
    inputStream.open(in_fname);
    if (!inputStream.is_open()) {
        return;
    }
    string line;
    int tempSize = chunk_size;
    string *chunk = new string[chunk_size];
    int i = 0;
    int chunkNo = 1;
    int chunks = 0;
    long total = 0;
    while (getline(inputStream, line)) {
        //cout << "Current chunk contains: \n";
        //cout << "loop 1: " << line << endl;
        //cout << "next word is : " << line << endl;
        chunk[i] = line;
        total++;
        i++;
        while (tempSize>1) {
            getline(inputStream, line);
            //cout << "next word is : " << line << endl;
            if (line == "") {
                tempSize--;
                chunk[i] = "";
                i++;
                continue;
            }
            //cout << "entered here with word:" << line<< endl;
            chunk[i] = line;
            i++;
            total++;
            tempSize--;
            //cout << "loop 2: " << line << endl;
        }
        i = 0;
        tempSize = chunk_size;
        /*cout << "current chunk:\n";
        for (int i = 0; i < chunk_size; i++) {
            cout << chunk[i] << endl;
        }*/
        sort(chunk, 0, chunk_size-1);
        //making the chunk file
        stringstream ss;
        ss <<"chunk"<<setfill('0')<<setw(5)<< chunkNo++;
        string s = ss.str();
        string chunk_name = chunk_location + s;
        ofstream myfile(chunk_name);
        for(int k = 0 ; k < chunk_size; k++){
            //cout << chunk[k] << endl;
            myfile << chunk[k] << endl;
        }
        chunks++;
    }
    k_merge(chunk_location, out_fname, chunks, total, chunk_size);
    delete[] chunk;
    return;
}

int partition (string arr[], int low, int high) {
    
    string pivot;// = arr[high];
    int temp = high;
    while (temp) {
        if (arr[temp] == "") {
            temp--;
        }
        pivot = arr[temp];
        break;
    }
    int i = low;
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j].compare (pivot) <= 0 && arr[j] != "")
        {
            
            std::swap(arr[i], arr[j]);
            
            i++;
        }
    }
    
    std::swap(arr[i], arr[high]);
    
    return i;
}

/*
	Your favorite n*log(n) sorting algorithm.
	Be sure that you use an in-place version of the algorithm.
	i.e. It does not generate a new array to return, but rather
	works by swapping elements in the input array.
	
	Possible options:
		-Quicksort
		-Mergesort
		-Heapsort
		
*/

void sort(string arr[], int low, int high) {
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
        
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}



// Merges the k temporary files
void k_merge(string chunk_location, string out_fname, int num_chunks, long total, int chunk_size)
{
    int chunkNo = 1;
    stringstream ss;
    ifstream * streams = new ifstream[num_chunks];
    ofstream out(out_fname);
    for (int i = 0; i < num_chunks; i++) {
        ss <<"chunk"<<setfill('0')<<setw(5)<< chunkNo++;
        string s = ss.str();
        ss.str("");
        string chunk_name = chunk_location + s;
        streams[i].open(chunk_name);
        //cout << "stream to file open: " << chunk_name << endl;
    }
    long currentCt = 0;
    string *container = new string[num_chunks];
    for (int i = 0; i < num_chunks; i++) {
        getline(streams[i],container[i]);
        while (container[i] == "") {
            getline(streams[i],container[i]);
        }
        //cout << container[i] << endl;
    }
    while (currentCt < total) {
        int index = min(container, num_chunks);
        out << container[index] << endl;
        //cout << "index: " << index << endl;
        //cout << container[index] << "\n";
        //cout << container[index] << endl;
        //cout << container[index] << endl;
        getline(streams[index], container[index]);
        //cout << container[index] << endl;
        currentCt++;
    }
    
	return;
}

int min (string container[], int num_chunks) {
    int index, flag = 0;
    string min;
    for (int i= 0; i < num_chunks; i++) {
        if (container[i] !="") {
            //cout<< "still contains " << container[i] << endl;
            flag = 0;
            break;
        }
        flag = 1;
    }
    if (flag == 1) {
        return 0;
    }
    for ( int j = 0; j < num_chunks; j++ ) {
        if (container[j] != "") {
            min = container[j];
            index = j;
            break;
        }
    }
    //cout << "Current Container: \n";
    for (int i = 0; i < num_chunks; i++ ) {
        //cout << container[i] << endl;
        if (container[i] != "") {
            if (container[i] < min) {
                min = container[i];
                index = i;
            }
        }
    }
    //cout << "returned element is : " << container[index] << endl;
    return index;
}
/*void mergeKlists(ifstream list[], int from, int to) {
    
    if (from == to) {
        return list[from];
    }
    if (from + 1 == to) {
        return mergeTwoLists(list[from], list[to]);
    }
    int m = (from + to) / 2;
    ifstream list1 = mergeKlists(list, from, m);
    ifstream list2 = mergeKlists(list, m+1, to);
    return mergeTwoLists(list1, list2);
}*/























