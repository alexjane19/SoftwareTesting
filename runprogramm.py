import os
import subprocess

# output = open("output.txt", "w+")
# subprocess.call(['/home/alex/Projects/Python/SoftwareTest/Test_Code_PlayingwithDice/sample', '8', '3', '4'], stdout=output)

# print("hello")
# import shlex, subprocess
# command_line = input()
# # /bin/vikings -input eggs.txt -output "spam spam.txt" -cmd "echo '$MONEY'"
# args = shlex.split(command_line)
# print( args)
# # ['/bin/vikings', '-input', 'eggs.txt', '-output', 'spam spam.txt', '-cmd', "echo '$MONEY'"]
# p = subprocess.Popen(args) # Success!


# statinfo = os.stat('outputs/output_BVA_2-3-5.txt')
# print(statinfo.st_size)
# open()
checked = ["01", "02", "03", "04"]
with open("/home/alex/Projects/Python/SoftwareTest/outputs/output_EC_5-2-5.txt") as infile:
    s = infile.readlines();
    s = s[-1:]
    s = s[0].rstrip(' \n')
    s = s[-2:]

    print(s[-2:])
#     for line in infile:
#         line = line.rstrip('\n')
#         print(line)
# a = line[-2:]
# print(a)
if s not in checked:
    print("ok")
