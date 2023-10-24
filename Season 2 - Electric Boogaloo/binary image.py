from PIL import Image

def create_image_from_binary(binary_data, width, height):
    # Create a new blank image with the specified dimensions
    image = Image.new("1", (width, height))  # "1" mode is for 1-bit pixels (black and white)

    # Create a pixel map for the image
    pixels = image.load()

    # Ensure the binary data has the correct length
    if len(binary_data) != width * height:
        raise ValueError("Binary data length doesn't match image dimensions")

    # Iterate through the binary data and set pixel values
    for y in range(height):
        for x in range(width):
            # Get the value from the binary data and convert it to an integer
            pixel_value = int(binary_data[y * width + x])
            # Set the pixel color based on the value (0 or 1)
            pixels[x, y] = pixel_value

    return image

# Example usage:
binary_data = "0000000100001001101101000000001111101111000010110110111110010001011010100001010101000100100010111001010101101010001001000101110001000100110100010011111011010100111010101111100000000101010101010101000000011111111001100100111111111111001001011011010111110101111100010001111011101101111100111011011100001101101111001110011100010101111110100110000001111111000100011111011011011101000101111000100110001110001011010001011011111010100010001101110111000010111110100100001000111000000000100110011111011001101111010100110000001011000010110100010000111011110011000110011111010110111000001000000011001010110010110000010001111111100110101110101110111000000001100011000000010100111011111011100010110100111001010100010101100110111000000100101000101000111110111001010010010001011110000010001010000000111110101101111110010000001000000001011101000011001100111"  # Replace this with your binary data
width = 29  # Replace this with the desired width of the image
height = 29  # Replace this with the desired height of the image

image = create_image_from_binary(binary_data, width, height)
image.save("binary_image.png")  # Save the image to a file (you can change the format)
image.show()  # Display the image