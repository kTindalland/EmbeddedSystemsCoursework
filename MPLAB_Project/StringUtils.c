int StringLength(char s[]) {
   int c = 0;
   while (s[c] != '\0') // While Current Character Is Not Null Terminator
      c++;
   
   return c;
}

void Concatenate(char sA[], char sB[], char result[])
{
    // Storing Contents of A in Result
	for (int i = 0; i < sizeA; i++)
	{
		result[i] = sA[i];
	}

    // Storing Contents of A in Result
	for (int i = 0; i < sizeB; i++)
	{
		result[i + sizeA] = sB[i];
	}

    // Add Terminating Character
	result[sizeA + sizeB] = '\0';
}