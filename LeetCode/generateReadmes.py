import os


def directory_name_to_url(directory_name):
    url_base = "https://leetcode.com/problems/"
    url_postfix = "/description"
    _, string_without_number = directory_name.split(" - ", 1)
    string_without_dashes = string_without_number.replace(" - ", " ")
    string_spaces_to_dashes = string_without_dashes.replace(" ", "-")
    string_lower_case = string_spaces_to_dashes.lower()
    url = url_base + string_lower_case + url_postfix
    return url


# Function to generate a Readme.md content
def generate_readme_content(directory_name, accepted_file_name=None):
    url = directory_name_to_url(directory_name)
    link_string = f"[1]: <{url}> \"Problem Webpage\""
    
    content = f"# {directory_name}\n\nSee the problem description. [LeetCode][1]\n\n"
    
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
