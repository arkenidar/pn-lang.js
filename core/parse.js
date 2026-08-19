
var write_line = console.log
var program_test_1 = ' @write-line "hello dear friends \\\\" \\n \\ \\\\ \\ \\" " '

var mode=''
var token=''
var list=[]
var escaping=false
var program = program_test_1
for(var i=0; i<program.length; i++){
	var character = program[i]
	var next_character = ''
	if((i+1)<program.length)
		next_character=program[i+1]
	//write_line(character)

	if(mode=='')
		if(character=='@' || character=='"')
			{ mode=character ; continue }
	
	if(!escaping && character=='\\' && next_character=='"' )
		{ escaping=true ; continue }

	var stop=mode=='"' && character=='"' && !escaping
	stop ||= mode=='@' && character==' '
	if(stop) {
		list.push([mode,token])
		mode='' ; token=''
	}

	if(mode!='') token += character
	escaping=false
}
write_line(list)
write_line(list[1][1])
