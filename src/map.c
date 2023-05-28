#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_physfs.h>
#include "zapengine/internal/zintern_map.h"
#include "zapengine/zlog.h"

ZAP_MAP *zap_create_empty_map(void)
{
    zlog(NONE, "Creating Empty Map.");
    ZAP_MAP *map = malloc(sizeof(ZAP_MAP));
    memset(map, 0, sizeof(ZAP_MAP));
    strcpy(map->header, "ZMAP\0");
    return map;
}

ZAP_MAP *zap_load_map(const char *mapfile)
{
    zlog(NONE, "Loading map from file %s", mapfile);
    ZAP_MAP *map = zap_create_empty_map();
    ALLEGRO_FILE *fp;
    fp = al_fopen(mapfile, "rb");

    al_fread(fp, (ZAP_MAP *)map, sizeof(ZAP_MAP));

    if (strcmp("ZMAP", map->header) == 0)
        zlog(INFO, "File is a ZMAP file.");
    else
    {
        zlog(FAIL, "File is not a ZMAP file! %s", map->header);
        return NULL;
    }
    al_fclose(fp);

    zlog(INFO, "Map %s loaded.", map->name);
    return map;
}

ZAP_MAP *zap_save_map(ZAP_MAP *map, const char *mapfile)
{
    al_set_standard_file_interface();
    zlog(NONE, "Saving map to file %s", mapfile);
    ALLEGRO_FILE *fp;
    fp = al_fopen(mapfile, "wb");

    al_fwrite(fp, (ZAP_MAP *)map, sizeof(ZAP_MAP));
    al_fclose(fp);

    zlog(INFO, "Map file %s saved.", map->name);
    al_set_physfs_file_interface();
    return map;
}

void zap_destroy_map(ZAP_MAP *map)
{
    zlog(NONE, "Destroying map %s", map->name);
    if (map) free(map);
    zlog(INFO, "Map destroyed");
}

void zap_set_map_name(ZAP_MAP *map, const char *name)
{
    zlog(NONE, "Setting map name.");
    strncpy_s(map->name, sizeof(map->name), name, 32);
    zlog(INFO, "Map name set to %s.", map->name);
}
