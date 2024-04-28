from fastapi import APIRouter,Depends,HTTPException
from pydantic.datetime_parse import date

from db import Base,engine,get_db

from sqlalchemy.orm import Session

from routes.auth import get_current_active_user
from schemas.users import UserCurrent

Base.metadata.create_all(bind=engine)
from functions.parametrs import *
from schemas.parametrs import *

router_parametr = APIRouter()

@router_parametr.post('/add')
def add_parametr(form:ParametrsCreate,db: Session = Depends(get_db),current_user: UserCurrent = Depends(get_current_active_user)):

    if add_parametrs(form=form,db=db):
        raise HTTPException(status_code=200, detail="Amaliyot muvofaqqiyatli bajarildi")


@router_parametr.get('/',status_code=200)
def get_parametr(search:str=None,id:int=0,from_date:str=None,end_date:str=None,page:int=1,limit:int=5,status:bool=None,db: Session = Depends(get_db),current_user: UserCurrent = Depends(get_current_active_user)):

        return all_parametrs(db=db,status=status,search=search,id=id,from_date=from_date,end_date=end_date,page=page,limit=limit)



@router_parametr.put('/update',)
def update_topic(form:ParametrsUpdate,db: Session = Depends(get_db),current_user: UserCurrent = Depends(get_current_active_user)):

    if update_parametrs(id=form.id,form=form,db=db):
        raise HTTPException(status_code=200, detail="Amaliyot muvofaqqiyatli bajarildi")

@router_parametr.delete('/del',)
def delete_topic(id:int,db: Session = Depends(get_db),current_user: UserCurrent = Depends(get_current_active_user)):
    return delete_parametrs(id=id,db=db)


