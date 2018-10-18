import os
from random import randint
# from random import uniform # Random float:  2.5 <= x < 10.0
from sys import maxsize
import itertools
import csv
import subprocess

keys = ["n", "m", "p"]
minsize = -maxsize + 1

not_error = []
runtime_error = []
output_error = []

checked = ["01", "02", "03", "04"]
def check_file(filename, i):
    statinfo = os.stat(filename)
    if statinfo.st_size == 0:
        runtime_error.append(i)
        output = open(filename, "w")
        output.write("Runtime error\n")
        return;
    else:
        with open(filename) as infile:
            s = infile.readlines();
            s = s[-1:]
            s = s[0].rstrip(' \n')
            a = s[-2:]
        if a not in checked:
            output_error.append(i)
            return;
    not_error.append(i)


def save_in_csv_file(length,matrix):
    print("\n")
    print(length)
    _name_file_csv = "output_{}.csv".format(length)
    with open(_name_file_csv, 'w') as csvfile:
        _field_names = []
        _field_names.append("Test Case")
        for i in keys:
            _field_names.append(i)
        writer = csv.DictWriter(csvfile, fieldnames=_field_names)
        writer.writeheader()
        i = 0
        for t in matrix:
            app_dir = ['Test_Code_PlayingwithDice/sample']
            row = {}
            i += 1
            row.update({'Test Case': i})
            print('Test Case {}'.format(i))
            for j in range(len(t)):
                row.update({_field_names[j+1]: t[j]})
                print(t[j])
                app_dir.append(str(t[j]))
            writer.writerow(row)
            name_output_file = "outputs/output_{}_{}-{}-{}.txt".format(length,app_dir[1],app_dir[2],app_dir[3])
            output = open(name_output_file, "w+")
            # output.write("Test Case: {} {} {}\n".format(app_dir[1],app_dir[2],app_dir[3]))
            print(app_dir)
            subprocess.call(app_dir, stdout=output)
            check_file(name_output_file, i)

_num_variable = 0;
_threshold_variables = {}


_min = eval(input("Please Enter Min rows and columns : "))
_max = eval(input("Please Enter Max rows and columns : "))
_threshold_variables.update({str(keys[_num_variable]): [_min, _max]})
_num_variable+=1


_min = eval(input("Please Enter Min Players : "))
_max = eval(input("Please Enter Max Players : "))
_threshold_variables.update({str(keys[_num_variable]): [_min, _max]})
_num_variable+=1


_min = eval(input("Please Enter Min traps : "))
# _max = eval(input("Please Enter Max traps : "))
_threshold_variables.update({str(keys[_num_variable]): [_min, 0]})
_num_variable+=1

def test_EC():
    _state_case =[]
    _state_template = []
    for i in keys:
        _case = []
        _l_min = _threshold_variables[i][0]
        if i == "p":
            _l_max = _state_case[0][0]
        else:
            _l_max = _threshold_variables[i][1]
        _state_template.append(['v','nv1','nv2'])
        _case.append(randint(_l_min,_l_max))
        _case.append(randint(minsize,_l_min-1))
        _case.append(randint(_l_max+1,maxsize))
        _state_case.append(_case)

    matrix = itertools.product(*_state_case)


    save_in_csv_file("EC", matrix)

def test_BVA():
    _state_case =[]
    for i in keys:
        _case = []
        _l_min = _threshold_variables[i][0]
        if i == "p":
            _l_max = _state_case[0][2]
        else:
            _l_max = _threshold_variables[i][1]

        _case.append(_l_min)
        _case.append(_l_min+1)
        _case.append(int((_l_min+_l_max)/2))
        _case.append(_l_max-1)
        _case.append(_l_max)
        _state_case.append(_case)


    # print(_state_case)
    _bva_case = []
    for i in range(len(_state_case)):
        for j in _state_case[i]:
            _case = []
            if i==0:
                _case.append(j)
                _case.append(_state_case[i+1][2])
                _case.append(_state_case[i+2][2])
                _bva_case.append(_case)
            if i==1:
                _case.append(_state_case[i-1][2])
                _case.append(j)
                _case.append(_state_case[i+1][2])
                _bva_case.append(_case)
            if i==2:
                _case.append(_state_case[i-2][2])
                _case.append(_state_case[i-1][2])
                _case.append(j)
                _bva_case.append(_case)

    # print(_bva_case)

    # matrix = itertools.product(*_state_case)


    save_in_csv_file("BVA", _bva_case)


def test_STH():
    _state_case =[]
    for i in keys:
        _case = []
        _l_min = _threshold_variables[i][0]
        if i == "p":
            _l_max = _state_case[0][3]
        else:
            _l_max = _threshold_variables[i][1]
        _case.append(_l_min-1)
        _case.append(_l_min)
        _case.append(_l_min+1)
        _case.append(int((_l_min+_l_max)/2))
        _case.append(_l_max-1)
        _case.append(_l_max)
        _case.append(_l_max+1)

        _state_case.append(_case)


    print(_state_case)
    _bva_case = []
    for i in range(len(_state_case)):
        for j in _state_case[i]:
            _case = []
            if i==0:
                _case.append(j)
                _case.append(_state_case[i+1][3])
                _case.append(_state_case[i+2][3])
                _bva_case.append(_case)
            if i==1:
                _case.append(_state_case[i-1][3])
                _case.append(j)
                _case.append(_state_case[i+1][3])
                _bva_case.append(_case)
            if i==2:
                _case.append(_state_case[i-2][3])
                _case.append(_state_case[i-1][3])
                _case.append(j)
                _bva_case.append(_case)

    print(_bva_case)

    # matrix = itertools.product(*_state_case)


    save_in_csv_file("STH", _bva_case)


def test_WST():
    _state_case =[]
    for i in keys:
        _case = []
        _l_min = _threshold_variables[i][0]
        if i == "p":
            _l_max = _state_case[0][2]
        else:
            _l_max = _threshold_variables[i][1]

        _case.append(_l_min)
        _case.append(_l_min+1)
        _case.append(int((_l_min+_l_max)/2))
        _case.append(_l_max-1)
        _case.append(_l_max)
        _state_case.append(_case)


    # print(_state_case)
    # _bva_case = []
    # for i in range(len(_state_case)):
    #     for j in _state_case[i]:
    #         _case = []
    #         if i==0:
    #             _case.append(j)
    #             _case.append(_state_case[i+1][2])
    #             _case.append(_state_case[i+2][2])
    #             _bva_case.append(_case)
    #         if i==1:
    #             _case.append(_state_case[i-1][2])
    #             _case.append(j)
    #             _case.append(_state_case[i+1][2])
    #             _bva_case.append(_case)
    #         if i==2:
    #             _case.append(_state_case[i-2][2])
    #             _case.append(_state_case[i-1][2])
    #             _case.append(j)
    #             _bva_case.append(_case)

    # print(_bva_case)

    matrix = itertools.product(*_state_case)


    save_in_csv_file("WST", matrix)


def test_WST_STG():
    _state_case =[]
    for i in keys:
        _case = []
        _l_min = _threshold_variables[i][0]
        if i == "p":
            _l_max = _state_case[0][3] #            _l_max = _state_case[0][3]**2
        else:
            _l_max = _threshold_variables[i][1]
        _case.append(_l_min-1)
        _case.append(_l_min)
        _case.append(_l_min+1)
        _case.append(int((_l_min+_l_max)/2))
        _case.append(_l_max-1)
        _case.append(_l_max)
        _case.append(_l_max+1)
        _state_case.append(_case)


    matrix = itertools.product(*_state_case)

    save_in_csv_file("WST_STG", matrix)

def save_result(fi,typ):
    path_file ="";
    if typ == 0:
        path_file = "output_BVA.csv"
        fi.write("انجام آزمون مقدار مرزی")
        fi.write("\n")
    if typ == 1:
        path_file = "output_STH.csv"
        fi.write("انجام آزمون استحکام")
        fi.write("\n")
    if typ == 2:
        path_file = "output_WST.csv"
        fi.write("انجام آزمون بدترین حالت")
        fi.write("\n")
    if typ == 3:
        path_file = "output_WST_STG.csv"
        fi.write("انجام آزمون بدترین حالت قوی")
        fi.write("\n")
    if typ == 4:
        path_file = "output_EC.csv"
        fi.write("انجام آزمون کلاس هم ارزی")
        fi.write("\n")

    fi.write("تعداد آزمون های تولید شده: ")
    fi.write(str(len(not_error) + len(output_error) + len(runtime_error)))
    fi.write("\n")

    if len(runtime_error):
        fi.write("موارد آزمون ")
        for i in range(len(runtime_error)):
            fi.write(str(runtime_error[i]))
            if i<len(runtime_error)-1:
                fi.write(" و ")
        fi.write(": خطای حین اجرا را پیدا کرد.")
    fi.write("\n")

    if len(output_error):
        fi.write("موارد آزمون ")
        for i in range(len(output_error)):
            fi.write(str(output_error[i]))
            if i<len(output_error)-1:
                fi.write(" و ")
        fi.write(": تفاوت خروجی واقعی و خروجی مورد انتظار داشتیم.")
    fi.write("\n")

    if len(not_error):
        fi.write("موارد آزمون ")
        for i in range(len(not_error)):
            fi.write(str(not_error[i]))
            if i<len(not_error)-1:
                fi.write(" و ")
        fi.write(": درست کار کرد.")
    fi.write("\n")
    fi.write("تست کیس های تولید شده ی در این آزمون در فایل {} موجود می باشد.".format(path_file))
    fi.write("\n")
    fi.write("\n")


    output_error.clear()
    runtime_error.clear()
    not_error.clear()


try:
    os.makedirs("outputs/", 0o0755)
except OSError as e:
    if e.errno == 17:  # errno.EEXIST
        os.chmod("outputs/", 0o0755)

fi = open("final_result.txt", "w")

# test_BVA()
# save_result(fi,0)
# test_STH()
# save_result(fi,1)
# test_WST()
# save_result(fi,2)
test_WST_STG()
save_result(fi,3)
test_EC()
save_result(fi,4)

fi.close()


import webbrowser
webbrowser.open("final_result.txt")

# print(not_error)
# print(runtime_error)
# print(output_error)

#
# for case in itertools.product(*_state_template):
#     print(case)
#
