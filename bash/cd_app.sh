#!/bin/bash

menu_choice=""
current_cd=""
title_file="title.cdb"
tracks_file="tracks.cdb"
temp_file=/tmp/cdb.$$
trap 'rm -f $temp_file' EXIT

get_return(){
    echo -e "Please return \c"
    read x
    return 0
}

get_confirm() {
    echo -e "Are you sure? \c"
    while true
    do
        read x
        case "$x" in
            y | yes | Y | Yes | YES )
                return 0;;
            n | no | N | No | NO )
                echo 
                echo "Cancelled"
                return 1;;
            * )
                echo "Please enter yes or no" ;;
        esac
    done
}

set_menu_choice() {
    clear
    echo "Option :-"
    echo
    echo "  a) Add new CD"
    echo "  f) Find CD"
    echo "  c) Count the CDs and tracks in the catalog."
    if [ "$cdcatnum" != " " ]; then
        echo "  l) List tracks on $cdtitle"
        echo "  r) Remove $cdtitle"
        echo "  u) Update track information for $cdtitle"
    fi
    echo "  q) Quit"
    echo

    echo -e "Please enter choice then press return \c"
    read menu_chioce
    return
}

insert_title() {
    echo $* >> $title_file
    return 
}

insert_track() {
    echo $* >> $tracks_file
    return 
}

add_record_tracks(){
    echo "Enter track information for this CD"
    echo "When no more tracks enter q"

    cdtrack=1
    cdtitle=""
    while [ "$cdtitle" != "q" ]
    do
        echo -e "Track $cdtrac, track title? \c"
        read tmp
        cdtitle=${tmp%%,*}
        if [ "$tmp" != "$cdtitle" ] ; then
            echo "Sorry, no commas allowed"
            continue
        fi

        if [ -n "$cdtitle" ] ; then
            if [ -n "$cdtitle" != "q" ]; then
                insert_track $cdcatnum, $cdtrack, $cdtitle
            fi
        else
            cdtrac=$((cdtrack-1))
        fi
        cdtrack=$((cdtrack+1))
    done
}

add_record() {
    # Promt for the initial information

    echo -e "Enter catalog name \c"
    read tmp
    cdcatnum=${tmp%%,*}

    echo -e "Enter title \c"
    read tmp
    cdtitle=${tmp%%,*}

    echo -e "Enter type \c"
    read tmp
    cdtype=${tmp%%,*}
    
    echo -e "Enter artist/composer \c"
    read tmp
    cdac=${tmp%%,*}

    #check that they want to enter the information

    echo About to add new entry
    echo "$cdcatnum $cdtitle $cdtype $cdac"

    #if confirmed then append it to the titles file

    if get_confirm ; then
        insert_title $cdcatnum,$cdtitle,$cdtype,$cdac
        add_record_tracks
    else
        remove_records
    fi

    return    
}

find_cd() {
    if [ "$1" = "n" ] ; then
        asklist=n
    else
        asklist=y
    fi

    cdcatnum=""
    echo -e "Enter a string to search for in the CD titles \c"
    read searchstr
    if [ "$searchstr" = " " ] ; then
        return 0
    fi

    grep "$searchstr" $title_file > $temp_file

    set $(wc -l $temp_file)
    linesfound=$1

    case "$linefound" in
        0)  echo "Sorry, nothing found"
            get_return
            return 0
            ;;
        1)  ;;
        2)  echo "Sorry, not unique."
            echo "Found the following"
            cat $temp_file
            get_return
            return 0
    esac

    IFS=","
    read cdcatnum cdtitle cdtype cdac < $temp_file
    IFS=" "
    if [ -z "$cdcatnum" ] ; then
        echo "Sorry, could not extract catalog field from $temp_file"
        get_return
        return 0
    fi

    echo 
    echo Catalog number: $cdcatnum
    echo Title: $cdtitle
    echo Type: $cdtype
    echo Artist/Composer: $cdac
    echo

    get_return

    if [ "$asklist" = "y" ]; then
        echo -e "View tracks for this CD? \c"
        read x
        if [ "$x" = "y" ] ; then
            echo 
            list_tracks
            echo            
        fi
    fi

    return 1
}
