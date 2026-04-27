namespace MonsterType {
    enum MonsterType
    {
        orc,
        golbin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{
    MonsterType::MonsterType monster { MonsterType::troll };

    return 0;
}
