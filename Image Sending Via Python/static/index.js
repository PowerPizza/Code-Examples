document.querySelector(".fl").onchange = (eve)=>{
    let file_obj = eve.target.files[0];
    console.log(file_obj);
    let xml_svr = new XMLHttpRequest();
    xml_svr.open("POST", "/set_file");
    xml_svr.onload = ()=>{
        console.log(xml_svr.responseText);
    }

    let file_with_metadata = new Blob([file_obj.name, "!123!", file_obj])
    // xml_svr.send(file_obj);
    xml_svr.send(file_with_metadata);
}