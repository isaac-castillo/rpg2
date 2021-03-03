How this `tilemap` library works:

You can load a tilemap from a file:

```cpp
tilemap = tilemap::load_from_file("file_name.tmx");
```
A tilemap has tiles:
```cpp
std::vector<tile> tiles = tilemap.get_tiles();
```

A `tile` maps `layers` to `layer_states`, and each `layer_state` has a sprite, and a collision flag. 
There are three types of `layers`: a `ground_layer`, `middle_layer`, and a `collision_layer`.


```cpp
tile first_tile = tilemap.get_tile(0,0); //std::optional
bool collision = first_tile.has_collision();

sf::Sprite sprite;
//Sprite related behavior
tile.add_layer(layer::ground_layer. layer_state(sprite, false));
```


You can draw also tiles:

```cpp
for(auto const tile : tiles){
    window.draw()
}
```

You may be curious: Does this library have any references to things on the tile? The answer is no. 

It also doesn't come with any collision detection. You just load the tilemap, and draw it. It renders based on `layer`, so that the ground layer, then middle layer. The collision layer doesn't render, obviously. 


Regarding collision there's a few ideas we must untangle:

1. Whether the `layer` is a `collision_layer` If it is, we don't render it. 