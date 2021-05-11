//Function to find length of a string
int strLength(char string[]){
	int i=0;
	while(string[i]!='\0'){
		i++;
	}
	return i;
}

//Function to concate two given strings
char* strConcat(char string1[],char string2[]){	
  int length, j;

  length = 0;
  while (string1[length] != '\0') {
    ++length;
  }

  for (j = 0; string2[j] != '\0'; ++j, ++length) {
    string1[length] = string2[j];
  }
  string1[length] = '\0';
  return string1;
}

//Function to copy one string to another string
char* strCopy(char string1[],char string2[]){
	int i;
    for(i=0; string1[i]!='\0'; i++)
    {
        string2[i] = string1[i];
    }

    string2[i] = '\0';
	return string2;
}

//Function to compare two strings
int strCompare(char mj1[], char mj2[])  
{
    int i = 0, flag = 0;
    while(mj1[i] != '\0' && mj2[i] != '\0') 
    {
        
        if(mj1[i] != mj2[i]) 
        {
            flag = 1;
            break;
        }
        i++;
    }

    if(flag == 0 && mj1[i] == '\0' && mj2[i] == '\0')
        return 1;
    else
        return 0;
}

//Function to find the first occurence of a character in a given string
int findChar(char string[],char c)
{
	int i,pos=-1;
  for (i = 0; string[i] != '\0'; i++)
   {
    	if(string[i]==c)
    	{
    		pos=i+1;
    		break;
    	}
  }
  return pos; 
}

//Function to find if a substring is present in a string
int substringCheck(char string1[],char substring[]){
	int count1 = 0, count2 = 0, i, j, flag;
	while (string1[count1] != '\0')
        count1++;
    while (substring[count2] != '\0')
        count2++;
    for (i = 0; i <= count1 - count2; i++)
    {
        for (j = i; j < i + count2; j++)
        {
            flag = 1;
            if (string1[j] != substring[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    return flag;
}

//Function to reverse a string
char* strReverse(char *s){
	int length=0,i;
	char temp;
	
	while(*(s+length)!='\0'){
		length++;
	}
	for(i=0;i<length/2;i++){
		temp=*(s+i);
		*(s+i)=*(s+length-i-1);
		*(s+length-i-1)=temp;	
	}
	return s;
}
