import os
slash = '\\'
args_vs = "-p vs_4_0 -O 3"
args_fs = "-p ps_4_0 -O 3"

compiler_path = os.getcwd() + "\\lib\\bgfx\\.build\\shadercRelease.exe"

print("- Shader Compilation -")

shaders_root = 'res\\shaders'

for root, dirs, files in os.walk(shaders_root, topdown=False):
    for name in files:
        args = ""
        type = ""
        if name.endswith('.fs'):
            args = args_fs
            type = "fragment"
        elif name.endswith('.vs'):
            args = args_vs
            type = "vertex"
        else:
            continue

        print(f"- Compiling {name}")

        output_dir = f"src/_compiled/shaders/{root.split(slash)[-1]}/"

        if not os.path.isdir(output_dir):
            os.mkdir(f"src/_compiled/shaders/{root.split(slash)[-1]}/")

        cmd = f"{compiler_path} -i {os.getcwd()}\\lib\\bgfx\\src --type {type} --platform windows {args} -f {os.path.join(root, name)} -o src/_compiled/shaders/{root.split(slash)[-1]}/{name}.hpp --bin2c {name.replace('.', '_')}"

        os.system(cmd)
