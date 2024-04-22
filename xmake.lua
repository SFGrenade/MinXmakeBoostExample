set_project( "MinExample" )

set_version( "0.5.0", { build = "%Y%m%d", soname = true } )

set_warnings( "allextra" )

add_rules( "mode.debug", "mode.release", "mode.releasedbg", "mode.minsizerel" )
add_rules( "plugin.compile_commands.autoupdate", { outputdir = ".vscode" } )

if is_plat( "windows" ) then
    -- let's just use 17
    set_languages( "cxx17" )

    add_cxflags( "/Zc:__cplusplus" )
    add_cxflags( "/Zc:preprocessor" )

    add_cxflags( "/permissive-" )
else
    -- let's just use 17
    set_languages( "c++17" )
end

add_requireconfs( "*", { configs = { shared = get_config( "kind" ) == "shared" } } )

add_requires( "boost" )

add_requireconfs( "boost", { configs = { serialization = true } } )

target( "MinExample" )
    set_kind( "binary" )
    set_default( true )
    set_group( "EXES" )

    add_packages( "boost", { public = true } )

    add_files( "src/*.cpp" )

    before_run( function ( target )
        import( "private.action.run.runenvs" )
        local addenvs, setenvs = runenvs.make( target )
        print( "addenvs", addenvs )
        print( "setenvs", setenvs )
    end )
