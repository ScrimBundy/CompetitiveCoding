import os


# Function to generate a Readme.md content
def generate_readme_content(directory_name, accepted_file_name=None):
    url_base = "https://open.kattis.com/problems/"
    stripped_directory_name = directory_name.replace(" ", "").lower()
    url = url_base + stripped_directory_name
    link_string = f"[1]: <{url}> \"Problem Webpage\""
    
    content = f"# {directory_name}\n\nSee the problem description. [Kattis][1]\n\n"
    
    if not accepted_file_name == None:
        date = accepted_file_name.split("_")[0]
        content = content + f"First Accepted: {date}\n\n"
    
    content = content + link_string + "\n"
    return content


# Function to create a Readme.md file in each subdirectory
def create_readme_files(root_directory):
    count = 0
    for item in os.listdir(root_directory):
        item_dir = os.path.join(root_directory, item)
        if not os.path.isdir(item_dir):
            continue
        
        readme_path = os.path.join(item_dir, "Readme.md")
        if os.path.exists(readme_path):
            # Skip subdirectories that already have a Readme.md
            continue
        
        count += 1
        accepted_path = os.path.join(item_dir, "Accepted")
        accepted_file = None
        if os.path.exists(accepted_path):
            accepted_files = os.listdir(accepted_path)
            accepted_files.sort()
            accepted_file = accepted_files[0]
        
        readme_content = generate_readme_content(item, accepted_file)
        with open(readme_path, "w") as readme_file:
            readme_file.write(readme_content)
    print(f"Generated {count} Readme.md files.")


if __name__ == "__main__":
    script_directory = os.path.dirname(os.path.abspath(__file__))  # Get the directory of the script
    create_readme_files(script_directory)
