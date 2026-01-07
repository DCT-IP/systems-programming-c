/*Binary files and C
.. has a collection of 0s and 1s
.. structures of a binary files are on the disc thus a very large collection can be made
.. these are perma and always avail, but slow as disc access time
.. random access available and readily changeable
.. for opening
.. fopen("name.bin","rb")
.. fread(name_var,sizeof(name_var),1,FILE_ptr)
.. *fwrite to write
.. fwrite(var,sizeof(var),1,write_ptr) and open wrt wb*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *ptr;
    int arr[] = {2,4,6,9};
    ptr = fopen("some.bin","wb");
    if(ptr == NULL)
        printf("The file is not opened!!\n");
    else{
        printf("File made...Entering Data\n");
        fwrite(&arr,sizeof(int),4,ptr);
        //fwrite(ptr,size,count,file_ptr) 
        printf("Data sucessfully entered!\n");
        fclose(ptr);
    }
    //writing into files done
    //onto reading
    int arrans[4];
    ptr = fopen("some.bin","rb");
    if(ptr == NULL)
        printf("The file is not opened!!\n");
    else{
        printf("File found!!!\n");
        fread(arrans,sizeof(int),4,ptr);
        for(int i =0;i<4;i++){
            printf("%d ",arrans[i]);
        }
        fclose(ptr);
    }
}