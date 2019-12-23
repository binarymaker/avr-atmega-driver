import re

findfile = open('test.h','r')
replacefile = open('testreplace.h','w')

int8 = re.compile("_SFR_IO8|_SFR_MEM8")
int16 = re.compile("_SFR_IO16|_SFR_MEM16")
int32 = re.compile("_SFR_IO32|_SFR_MEM32")

for line in findfile:
    match = int8.findall(line)
    text_detect = 0
    if len(match) != 0:
        match = line.split(' ')
        sfr_macro = match[1]
        replace_text = "#define %s %s\nuint8_t %s ;\n\n" %(sfr_macro,sfr_macro,sfr_macro)
        replacefile.write(replace_text)
        text_detect = 1
    
    match = int16.findall(line)
    if len(match) != 0:
        match = line.split(' ')
        sfr_macro = match[1]
        replace_text = "#define %s %s\nuint16_t %s ;\n\n" %(sfr_macro,sfr_macro,sfr_macro)
        replacefile.write(replace_text)
        text_detect = 1
        
    match = int32.findall(line)
    if len(match) != 0:
        match = line.split(' ')
        sfr_macro = match[1]
        replace_text = "#define %s %s\nuint32_t %s ;\n\n" %(sfr_macro,sfr_macro,sfr_macro)
        replacefile.write(replace_text)
        text_detect = 1
    
    if(text_detect == 0):
        replacefile.write(line)


print("Completed...")
findfile.close()
replacefile.close()