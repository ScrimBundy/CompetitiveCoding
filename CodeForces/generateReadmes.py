import os


# Function to generate a Readme.md content
def generate_readme_content(parent_directory_name, directory_name, accepted_file_name=None):
    url_base = "https://codeforces.com/problemset/problem/"
    url = url_base + parent_directory_name + "/" + directory_name
    link_string = f"[1]: <{url}> \"Problem Webpage\""
    
    content = f"# {directory_name}\n\nSee the problem description. [CodeForces][1]\n\n"
    
    if not accepted_file_name == None:
        date = accepted_file_name.split("_")[0]
        content = content + f"First Accepted: {date}\n\n"
    
    content = content + link_string + "\n"
    return content


def create_problem_readme_file(directory, contest_dir_name, problem_dir_name):
    readme_path = os.path.join(directory, "Readme.md")
    if os.path.exists(readme_path):
        # Skip subdirectories that already have a Readme.md
        return 0

    accepted_path = os.path.join(directory, "Accepted")
    accepted_file = None
    if os.path.exists(accepted_path):
        accepted_files = os.listdir(accepted_path)
        accepted_files.sort()
        accepted_file = accepted_files[0]
            
    readme_content = generate_readme_content(contest_dir_name, problem_dir_name, accepted_file)
    with open(readme_path, "w") as readme_file:
        readme_file.write(readme_content)
    
    return 1


def create_contest_readme_files_recursive(directory, contest_dir_name):
    count = 0
    
    for item in os.listdir(directory):
        item_dir = os.path.join(directory, item)
        if not os.path.isdir(item_dir):
            continue
        count += create_problem_readme_file(item_dir, contest_dir_name, item)
        print(item_dir)
        
        break # stop after the first level of subdirectories
    
    return count


# Function to create a Readme.md file in each subdirectory
def create_readme_files(root_directory):
    count = 0
    for item in os.listdir(root_directory):
        item_dir = os.path.join(root_directory, item)
        if os.path.isdir(item_dir):
            count += create_contest_readme_files_recursive(item_dir, item)
            
    print(f"Generated {count} Readme.md files.")


if __name__ == "__main__":
    script_directory = os.path.dirname(os.path.abspath(__file__))  # Get the directory of the script
    create_readme_files(script_directory)
