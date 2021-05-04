


from pathlib import Path
import os

dmenu_items = Path("dmenu_items.txt")
dmenu_urls = Path("bookmarks/bookmarks.txt")
dmenu_all = Path("dmenu_items_urls.txt")

dmenu_all.write_text(
    dmenu_items.read_text() + "\n" + dmenu_urls.read_text()
)


dmenu_items_cache = Path(os.path.expanduser("~/.cache/dmenu_items.txt"))
dmenu_items_cache.write_text(dmenu_all.read_text())
