#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        //open the memory card for reading, pointer file points to memory card.
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("Could not open raw file or empty file");
            return 1;
        }
        
        //created a pointer to a new file to write what is readed
        FILE *img = NULL;
        
        //created a temporary space to store what is readed from file
        unsigned char buffer[512];
        
        int counter = 0;
        int title = 0;
        
        //array for naming new jpeg files
        char filename[8];
        
        //read from file until it reaches the end of the file
        while (fread(buffer, 512, 1, file) == 1)
        {
            // read from file and store it in buffer
            // fread(buffer, 512, 1, file);
            
            //looking at first 4 bytes of buffer to determine if it is beginning of jpeg
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                /*if it is beginning of a jpeg file but before this if you were already writing an file, that means
                you have to close the previous file and create a new jpeg file(write a new image). If counter is 0, then it means you are in first jpeg,
                no need to close previous one.*/
                if (counter == 1)
                {
                    fclose(img);
                }
                else
                {
                    //if you pass the first file, counter is 1 from now on so that you will always close the previous file before start a new one.
                    counter = 1;
                }
                
                //format the name of jpeg files.
                sprintf(filename, "%03d.jpg", title++);
                
                //open new jpeg file to writing in it, pointer img, points to these new files by one by
                img = fopen(filename, "w");
            }
            /*If it is not a beginning of jpeg file but if one jpef is already founded before (because counter becomes 1 if so), 
            then it should keep writing to it */
            if (counter == 1)
            {
                fwrite(&buffer, 512, 1, img);
                
            }
            
        }
        if (img != NULL)
        {
            fclose(img);
        }
        fclose(file);
    }
    else
    {
        return 1;
    }
    return 0;
}
