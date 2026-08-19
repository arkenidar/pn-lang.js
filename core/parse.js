
var write_line = console.log
var program_test_1 = ' @write-line "hello dear friends " '

var mode=''
var token=''
var list=[]
var program = program_test_1
for(var i=0; i<program.length; i++){
	var character=program[i]
	//write_line(character)

	if(mode=='')
		if(character=='@' || character=='"')
			{ mode=character ; continue }

	var stop=mode=='"' && character=='"'
	stop ||= mode=='@' && character==' '
	if(stop) {
		list.push([mode,token])
		mode='' ; token=''
	}

	if(mode!='') token += character
}
write_line(list)
