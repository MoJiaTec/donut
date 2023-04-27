import platform
import os

BuildPath = "Build"
BinPath = "Bin"

def main():
    systemName = platform.system()
    print("Building On " + systemName + " System")


    dir_path = os.path.dirname(os.path.realpath(__file__))
    print("Current Path is " + dir_path)

    if not os.path.isdir(dir_path + '/' + BuildPath + '/'):
        os.mkdir(dir_path + '/' + BuildPath + '/')

    if not os.path.isdir(dir_path + '/' + BinPath + '/'):
        os.mkdir(dir_path + '/' + BinPath + '/')

    if systemName == "Windows":
        os.chdir(dir_path + '/' + BuildPath)
        os.system('cmake -G "Visual Studio 17 2022" -A x64 ../')


if __name__ == "__main__":
    main()