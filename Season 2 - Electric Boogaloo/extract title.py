from PIL import Image
from PIL.PngImagePlugin import PngInfo

def extract_titles_from_pngs():
    for i in range(484):  # Assuming you have files 0.png, 1.png, 2.png, etc.
        filename = f"{i}.png"
        try:
            with Image.open(filename) as img:
                # Extract the title from the image's metadata
                metadata = img.info.get("Title", "")
                if metadata:
                    print(metadata, end='')
                else:
                    print(f"No title found for {filename}")
        except FileNotFoundError:
            print(f"{filename} not found")
        except Exception as e:
            print(f"Error processing {filename}: {str(e)}")

if __name__ == "__main__":
    extract_titles_from_pngs()