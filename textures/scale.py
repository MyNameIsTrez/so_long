from pathlib import Path
from PIL import Image


texture_dir_path = Path("BitsyDungeonTiles/textures")
original_texture_path = texture_dir_path / "scale_1.png"

scale = 5


def main():
	with Image.open(original_texture_path) as im:
		im.resize((im.width * scale, im.height * scale)).save(texture_dir_path / ("scale_" + str(scale) + ".png"))


if __name__ == "__main__":
	main()
